#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void radix (int byte, long N, long *source, long *dest)
{
    long count[256];
    long index[256];
    int i;
    memset (count, 0, sizeof (count));
    for (i=0; i<N; i++ )
        count[((source[i])>>(byte*8))&0xff]++;
        index[0]=0;
    for ( i=1; i<256; i++ )
        index[i]=index[i-1]+count[i-1];
    for ( i=0; i<N; i++ )
        dest[index[((source[i])>>(byte*8))&0xff]++] = source[i];
}
void radixsort (long *source, long *temp, long N)
{
    radix (0, N, source, temp);
    radix (1, N, temp, source);
    radix (2, N, source, temp);
    radix (3, N, temp, source);
}

void make_random (long *data, long N)
{
    for (int i=0; i<N; i++ )
        data[i]=rand()|(rand()<<16);
}
long data[100];
long temp[100];

int main (void)
{
    cout<<"*======================================Tugas Praktikum Sorting======================================*"<<endl;
    cout<<" Struktur Data & Pemrograman"<<endl;
    cout<<" Latihan 5 - Radix Sorting"<<endl;
    cout<<" Created By Abdul Latif Munjiat (1610631170004)"<<endl;
    cout<<" Kelas 3'A Fasilkom Unsika\n"<<endl;
    make_random(data, 100);
    radixsort (data, temp, 100);
    for ( int i=0; i<100; i++ )
        cout<<data[i] << '\n';
}
