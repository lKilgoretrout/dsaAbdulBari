#include <stdio.h>
#include <stdlib.h>

// using 0 indexing for row and column numbers

struct Element
{
    int row;  // row
    int col;  // col
    int val; // value
};

struct SparseMatrix
{
    struct Element* elements; // array of Element structs
    int rows; 
    int cols;
    int num;  // number of non-zero elements

};

struct SparseMatrix CreateSparseMatrix()
{
    int rows, cols;
    printf("\nEnter number of rows: ");
    scanf("%d", &rows);
    printf("\nEnter number of columns: ");
    scanf("%d", &cols);
    
    struct Element* elements = (struct Element*) malloc(rows*cols * sizeof(struct Element));
    int  val;
    struct Element e = {0, 0, 0};

    int index = 0;
    int num = 0;                                // number of non-zero elements in SparseMatrix
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            printf("\nEnter a value for row %d, col %d : ", i+1, j+1);
            scanf("%d", &val);
            if (val != 0) 
            {                
                e.row = i;
                e.col = j;
                e.val = val;
                num++;
                elements[index] = e;
                index++;
            }
        }
    }

    elements = realloc(elements, num * sizeof(struct Element));        // elements only contains non-zero values
    struct SparseMatrix s = {elements, rows, cols, num};

    return s;
}


struct SparseMatrix AddSparseMatrices(struct SparseMatrix* m1, struct SparseMatrix* m2)
{
    int i=0; int j=0; int k=0;            // m1 elements index, m2 elements index, m3 elements index respectively
    int num=0;                 // m1.elements[i] + m2.elements[j]  ,  num of non-zero elements in sum matrix

    struct Element* elements = (struct Element*) malloc(m1->rows * m1->cols * sizeof(struct Element)); // non-zero elements in sum matrix
    
    for (int row=0; row<m1->rows; row++)
    {
        for (int col=0; col<m1->cols; col++)
        {
            int val1=0; int val2=0; int sum=0;
            
            // if next element is the row/col we are on, set addend to corresponding value
            if (m1->num)
            {    
                if (m1->elements[i].row == row && m1->elements[i].col == col) 
                    val1 = m1->elements[i++].val;                               //*** increment index only if e.val is non-zero! *** 
            }
            if (m2->num)
            { 
                if (m2->elements[j].row == row && m2->elements[j].col == col)
                val2 = m2->elements[j++].val;           
            }
            sum = val1 + val2;
            
            if (sum)
            {
                struct Element e = {row, col, sum};
                elements[k] = e;
                k++;
                num++;
            }
        }
    }

    elements = realloc(elements, sizeof(struct Element) * num);       // zeroes? we don't want your kind in here
    struct SparseMatrix m3 = {elements, m1->rows, m1->cols, num};

    return m3;
}    


void Display(struct SparseMatrix s)
{
    int index = 0;                                // index of element in s to be printed
    for (int i=0; i<s.rows; i++)
    {
        for (int j=0; j<s.cols; j++)
        {
            if (s.num==0) 
                printf("0 ");
            else if (s.elements[index].row==i && s.elements[index].col==j)
            {
                printf("%d ", s.elements[index].val);
                index++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    printf("welcome to RJ's sparse matrix program!\n");

    struct SparseMatrix s1 = CreateSparseMatrix();
    Display(s1);

    struct SparseMatrix s2 = CreateSparseMatrix();
    Display(s2);

    printf("\n aight. now watch me add them shits together hella good:\n");

    struct SparseMatrix s3 = AddSparseMatrices(&s1, &s2);

    Display(s3);

}

