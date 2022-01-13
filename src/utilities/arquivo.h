bool escreveInteiroArquivo(const char * localizacao, int valor);
int leInteiroArquivo(const char *localizacao);

bool escreveInteiroArquivo(const char * localizacao, int valor)
{
    FILE *file = fopen(localizacao, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf(file, "%d", valor);
    fclose(file);

    return true;
}

int leInteiroArquivo(const char * localizacao)
{
    FILE* file = fopen (localizacao, "r");

    if (file == NULL)
    {
        return 0;
    }

    int i = 0;
    fscanf (file, "%d", &i);

    return i;
}