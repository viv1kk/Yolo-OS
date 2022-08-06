int i = 0;
unsigned short* VideoMemory = (unsigned short*)0xB8000;

void printf(char* str)
{
    for(int j = 0;str[j] != '\0'; ++i, j++)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | (char)str[j];
}

void printCharacters()
{
    for(int j = 0; j <= 127; ++j, ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | (char)j;
}

typedef void (*constructor)();

extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* j = &start_ctors; j != &end_ctors; j++)
    {
        (*j)();
    }
}

extern "C" void kernelMain(void* multiboot_structure, unsigned int magicnumber)
{
    printf("Welcome To Vivek's Kernel : ");
    printf("Here are 127 characters : ");
    printCharacters();
    while(1);
}
