# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

typedef struct Array
{
    int size;         // max num of elements
    int length;       // current num of elements
    float percentFull; // length / size , for Resize()
    int *A;
    
} Array;

void Display(Array *array)
{
    for (int i=0; i<array->length; i++)
        printf("%d ", array->A[i]);
    printf("\n");
}

// displays entire underlying array from index 0 to array->size
void DisplayUnderlying(Array *array)
{
    for (int i=0; i<array->size; i++)
        printf("%d ", array->A[i]);
    printf("\n");
}

/* doubles Array size if array.length / array.size >= 0.75
*  reduces size to 2 * array.size if 25% full
*/
void Resize( Array *array)
{   
	
	// double size?
    if (array->percentFull >= 0.75)
    {
        /*
		int *B;
        B = (int *) malloc(arraySize * 2 * sizeof(int));
        memset(B, '\0', arraySize * 2);
		//B = (int *)calloc(array->A, array->size * 2 * sizeof(int));
		for (int q=0; q<array->size; q++)
            B[q] = array->A[q];
        */
        // set the 'size' attribute of array:
        array->size *= 2;
        array->A = realloc(array->A, array->size * 2 * sizeof(int));
        
        //free(B);  //changes values in A !
		//B = NULL;
    }
	else if (array->percentFull <= 0.25)
	{
		/*
		int *C;
		C = (int *) malloc(array->length * 2 * sizeof(int));
		memset(C, '\0', array->length * 2);
		//C = (int *) calloc(array->A, array->length * 2 * sizeof(int));
		for (int j=0; j<array->length; j++)
			C[j] = array->A[j];
		*/
		array->size = array->length * 2;
		array->A = realloc(array->A, array->size * 2 * sizeof(int));
		//free(C);
		//C = NULL;
    }
}
    
// RETURN -1 on failure    
int Append( Array *array)
{
    int v;
    // % full for resizing:
    array->percentFull = ((float)(array->length)) / ((float)(array->size));
    
    int oldLength = array->length;
    if (array->percentFull > 0.75 )
        Resize(array);
      
    // Append()
    printf("value to append: ");
    scanf(" %d", &v);
    printf("Append(%d)...\n", v);
    
    array -> A[oldLength] = v;
    array -> length++;
    
    return 1;
}
// delete VALUE from INDEX;  RETURN -1 if failure, 1 if success
int Delete(Array *array)
{
    int index;
    printf("index to Delete() from: ");
    scanf(" %d", &index);
    if (index < 0 || index >= array->length || array->length==0)
    {
        printf("Invalid index\n");
        return -1;
    }
    if (array->length == 0)
    {    printf("Can't delete from empty array");
        return -1;
    }
    
    for (int i=index; i<array->length; i++)
        array->A[i] = array->A[i+1];
    
    array->length--;
    return 1;
}

// RETURN index of VALUE else -1;
int LinearSearch(Array *array)
{
    int v;
    printf("value to search for: ");
    scanf(" %d", &v);
    int index = -1;
    for (int i=0; i<array->length; i++)
        if (array->A[i] == v)
        {    
            index = i;
            printf("value %d found at index %d\n", v, i);
            return index;
        }
    printf("value %d not found in this array\n", v);
    return index;
}

// insert value at index in array; RETURN 1 on success, -1 on failure
int Insert(Array *array)
{
    ///////////////////////////////////////////////////////////////////
    // doesn't work right when array->size = array->length (for some reason!)
    int i, v;
    printf("index to Insert() to: ");
    scanf(" %d", &i);
    printf("value to insert at index %d: ", i);
    scanf(" %d", &v);
    if (i < 0 || i > array->length)
    {
        printf("Invalid index\n");
        return -1;
    }
    array->percentFull = ((float)(array->length)) / ((float)(array->size));
    //printf("percentFull: %f\n", array->percentFull);
    //printf("array->size, array->length = %d, %d\n", array->size, array->length);
    if (array->percentFull >= 0.75 || (array->length == array->size) )
    {
        Resize(array);
        printf("Resize!\n");
    }
    else
    {
        // scooch array values over to the right one:
        for (int j=array->length; j>i; j--)
            array->A[j] = array->A[j-1];
        array->length++;
        array->A[i] = v;
        
    }
    return 1;
}

void insertionSort(Array *array)
{
	for (int i=1; i<array->length; i++)
    {
		int current = array->A[i];
		int k;
		for (k=i-1; k>=0 && array->A[k]>current; k--)
			array->A[k+1] = array->A[k];
		
		array->A[k+1] = current;
	}	
}

// RETURNs true if sorted ascending, 0 if not
int isSorted(Array *array)
{
    if (array->length == 0 || array->length == 1)
    {
        printf("It's sorted !\n");
        return 1;
    }
    int low = array->A[0];
    
    for (int i=1; i<array->length; i++)
    {
        if (array->A[i] < low)
        {
            printf("It's not sorted ! %d at index %d is out of order!\n", 
                    array->A[i], i);
            return 0;
        }
        low = array->A[i];
    }
    printf("It's sorted !\n");
    return 1;
}

void Create(Array *arr)
{
    
    // create Array
    printf("Enter size of array: ");
    scanf(" %d", &arr->size);
    arr->A = (int *) malloc(arr->size * sizeof(int));
        
    printf("Enter number of elements to add to Array:");
    scanf(" %d", &arr->length);
    
	printf("Enter %d integers to add to Array:\n", arr->length);
    
    for (int i=0; i<arr->length; i++) { scanf(" %d", &arr->A[i]); }
	
	
	// if the user creates an array that's mostly full, resize() it
	arr->percentFull = ((float)(arr->length)) / ((float)(arr->size));
    if (arr->percentFull > 0.75)
		Resize(arr);
	
    
}

// creates an array of: 1 <= length < 42; and -
void CreateRandom(Array *arr)
{
    arr->length = (rand() % 87);
    arr->size   = arr->length *2;
    arr->A = (int *) malloc (arr->size * sizeof(int));
    
    for (int i=0; i<arr->length; i++)
        arr->A[i] = ( (rand() % 87) - 43 );
}
        
void Menu()
{
    printf("(M)enu              to display this menu again...\n");
    printf("(C)reate            an array and then try the following...\n");
    printf("(A)ppend            to current array\n");
    printf("(D)isplay           the current array\n");
    printf("Display(U)nderlying array of the dynamic array\n");
    printf("D(E)lete            to remove element at specified index\n");
    printf("(I)nsert            to the current array by value and index\n");
    printf("is(S)orted          to check if current array is sorted in ascending order\n");
    printf("(L)inearSearch      to check if current array contains a value\n");
    printf("create(R)andom      to fill the current array with random integers\n");
	printf("insertion(s)ort     to sort the current array in place in O(n^2) time\n");
    printf("(Q)uit              quit the program");
    printf("\n");
}

// prints prompt and returns commmand char 
char Prompt()
{
    char command;
    printf("Enter a command plz: ");
    scanf(" %c", &command);
    getchar();
    return command;
}

// calls arrayADT function and checks if valid command
// RETURNs 0 on 'Q'uit , 1 otherwise
int ExecuteCommand(char command, Array *arr)
{
    char input = command;
    
    switch(input)
    {
        case 'M':
            Menu();     
            break;
        case 'C':
            Create(arr);   
            break;
        case 'A':
            Append(arr);   
            break;
        case 'D': 
            Display(arr);  
            break;
        case 'U':
            DisplayUnderlying(arr); 
            break;
        case 'E':
            Delete(arr);
            break;
        case 'I':
            Insert(arr);
            break;
        case 'S':
            isSorted(arr);
            break;
        case 'L':
            LinearSearch(arr);
            break;
        case 'R':
            CreateRandom(arr);
            break;
	case 's':
            insertionSort(arr);
            break;
        case 'Q':
            return 0;
        default:
            printf("Sorry, \'%c\' is not a valid command\n", input);
            printf("\n");
    }
    return 1;
}

int commandShell(Array *arr)
{
    
    printf("Welcome to RJ's arrayADT program!\n\n");
    Menu(); 
    
    // keep taking commands until user enters 'Q'
    
    char input;
    int keepGoing = 1;
    while (keepGoing==1)   // input != 'Q'
    {
        input = Prompt();
        keepGoing = ExecuteCommand(input, arr);
    }
    printf("\nThanks for using my program, have a nice day !");
    
    return 1;
}
        
    
int main()
{
    Array arr;
    commandShell(&arr);
       
    return 0;
    
}
