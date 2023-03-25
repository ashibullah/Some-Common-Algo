#include <stdio.h>
#include <string.h>
struct facebook
{
  char username[10];
  char password[18];
  char bio[18];
  int friend;
};

int main()
{
  char ch, oldpass[20];
  char pass[] = "AshibCse25";
  char username[] = "ashibullah";
 
  struct facebook person1; 
  
  person1.friend = 970;
  strcpy(person1.bio,"Satisfied With Life");
  
  printf("Enter Your Username: ");
  gets(person1.username);
  printf("Enter Your Password: ");
  gets(person1.password);
 
  
  // strcmp(person1.password, pass);
  if (strcmp(person1.password, pass) ==0  || strcmp(person1.username, username) == 0 )
  {
    printf("Succesfully Login");
    printf("\n\n      Bio: %s", person1.bio);
    printf("\n             Friends: %d", person1.friend);
    
    printf("\nDo you want to Change your password?(y/n)\n");
    ch = getchar();

  }
  else printf("\nIncorrect Password\n");

  if (ch == 'y')
  {
    
  printf("\n You have decided to change password");
   printf("\n  Enter Old Password: ");
   scanf("%s", oldpass);
   if (strcmp(oldpass,pass) == 0)
   {
     printf("\nEnter New Password : ");
     scanf("%s", pass);
     printf("New Password Done");

   }
   else printf("Wrong Password");
   
  }
  else 
  printf("__________________");
  

}