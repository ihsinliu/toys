#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>       //for function access()
#include"tinydir.h"

char MenuText[10][38] = {"1.Create New Note\0",
"2.Append Note\0",
"3.Delete A Note\0",
"4.Search Note\0",
"5.NoteList(in progress)\0",
"6.View Note\0",
"7.\0",
"8.\0",
"9.\0",
"9.Exit\0"};

void Rootmenu()
{
    int i;
    for(i = 0;i < 10;i++)
    {
        printf("%s\n",MenuText[i]);
    }
}

int GetSelect()
{
    int iSel;
    scanf("%d",&iSel);
    if(iSel<=0 || iSel > 10)
    {
        printf("Input Error!!!\n");
        return 0;
    }
    else
        return iSel;
}


void Buffer()
{
    printf("Press ENTER to continue\n");
    getchar();
    getchar();
}

void NewNote()
{
    FILE *fp;
    char name[28];
    char content[10000];
    char ch;
    int i;
    int bcontinue = 1;
    int iSel;
    printf("Please enter the name of note:\n");
    scanf("%s",&name);
    fp = fopen(name,"w");
    printf("Please enter the content,end with #\n");
    for(i = 0;i < 10000;i++)
    {
        ch = getche();
        if(ch == '#')
        {
            content[i] = '\0';
            break;
        }
        content[i] = ch;
    }
    fwrite(content,strlen(content),1,fp);
    printf("\nSuccessfully Created\n");
    fclose(fp);
    Buffer();
}

void ModifyNote()
{
    FILE *fp;
    char name[28];
    char content[10000];
    char ch;
    int i;
    printf("Please enter the name of note:\n");
    scanf("%s",&name);
    if(access(name,"r") != -1)
    {
        printf("Note doesn't exixt\n");
        Buffer();
        return NULL;
    }
    fp = fopen(name,"a+");
    printf("Please enter the content to be appended.End with #\n");
    for(i = 0;i < 10000;i++)
    {
        ch = getche();
        if(ch == '#')
        {
            content[i] = '\0';

            break;
        }
        content[i] = ch;
    }
    fwrite(content,strlen(content),1,fp);
    printf("\nSuccessfully Modified!\n");
    fclose(fp);
    Buffer();
}

void DeleteNote()
{
    FILE *fp;
    char name[28];
    int i;
    printf("Please enter the name of note:\n");
    scanf("%s",name);
    if(remove(name) == 0)
        printf("Deleted successfully\n");
    else
        printf("Unable to delete the file\n");
    Buffer();
}

int isStringInFile(const char *fname,const char *str)
{
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	fp = fopen(fname, "r");
	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, str)) != NULL) {
			printf("A match found on line: %d\n", line_num);
			printf("\n%s\n", temp);
			find_result++;
		}
		line_num++;
	}

	fclose(fp);
    return 0;
}

void SearchContent()
{
    FILE *fp;
    char name[28];
    int i;
    char content[100];
    printf("Please enter the name of file\n");
    scanf("%s",name);
    if(access(name,"r") == 0)
    {
        printf("Note doesn't exist\n");
        Buffer();
        return NULL;
    }
    printf("Pleasd enter the content you want to find\n");
    scanf("%s",content);
    if(isStringInFile(name,content) != 0)
        printf("The content doesn't exist\n");
    Buffer();
}

void NoteList()                 //TODO
{
    printf("IN PROGRESS!!!\n");
    Buffer();
    return NULL;
    /*
    tinydir_dir dir;
    tinydir_open(&dir, "C:\Users\ihsin\Desktop\C Code");

    while (dir.has_next)
    {
        tinydir_file file;
        tinydir_readfile(&dir, &file);

        printf("%s", file.name);
        if (file.is_dir)
        {
            printf("/");
        }
        printf("\n");

        tinydir_next(&dir);
    }

    tinydir_close(&dir)
    */
}

void Viewnote()
{
    FILE *fp;
    char name[28];
    char content[10000];
    printf("Please enter the name of the note\n");
    scanf("%s",name);
    fp = fopen(name,"r");
    fread(content,sizeof(content),1,fp);
    printf("%s\n",content);
    Buffer();
}

void Mainloop()
{
    while(1)
    {
        system("CLS");
        Rootmenu();
        switch(GetSelect())
        {
            case 1:
                system("CLS");
                NewNote();
                break;
            case 2:
                system("CLS");
                ModifyNote();
                break;
            case 3:
                system("CLS");
                DeleteNote();
                break;
            case 4:
                system("CLS");
                SearchContent();
                break;
            case 5:
                system("CLS");
                NoteList();
                break;
            case 6:
                system("CLS");
                Viewnote();
                break;
            case 9:
                system("CLS");
                exit(0);

        }
    }
}



int main()
{
    system("cls");
    Mainloop();

    return 0;
}
