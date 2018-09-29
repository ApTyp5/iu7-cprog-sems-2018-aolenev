MATRIX* matrix_transpose( MATRIX* input_matrix)
{
    int k,j;
    MATRIX output_matrix;
    matrix_size( input_matrix, &k, &j );
    matrix_create(output_matrix, j, k);
    for(int f=0; f<k;f++)
    {
    for int(int g=0; g<j; g++)
    {
    tmp=matrix_get(f, g, input_matrix);
    matrix_set(g, f, output_matrix);
    }
    }
    matrix_delete(input_matrix)
    return output_matrix;


}