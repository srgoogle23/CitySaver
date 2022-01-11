int randInt(int n);
int randIntMinMax(int min, int max);
double randDouble();
double randDoubleMinMax(double min, double max);

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

// aleatorio double entre 0 e 1
double randDouble()
{
    return (double)rand()/RAND_MAX;
}

// aleatorio double entre min e max
double randDoubleMinMax(double min, double max)
{
    return min + randDouble()*(max - min);
}