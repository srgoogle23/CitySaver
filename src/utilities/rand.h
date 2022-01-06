int randInt(int n);
int randIntMinMax(int min, int max);

// aleatorio entre 0 e n-1
int randInt(int n)
{
    return rand()%n;
}

// aleatorio int entre min e max
int randIntMinMax(int min, int max)
{
    return min + randInt(max - min + 1);
}