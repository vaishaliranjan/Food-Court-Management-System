#include <iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

char un[20];
char sid[20];
char ft[20];

class Admin
{
    public:
    int totitem, price[10];
    char name[20],mail[20],mobile[15],fmenu[20][20];
    char  retype[20];
    char passwd[20], rpasswd[20];
    char restid[15],stallid[20];
    
    void menu()
    {   cout<<"____________________________________________________\n";
        cout<<"                       MENU                         \n";
        cout<<"____________________________________________________\n";
        cout<<"Food Item                              Price        \n";
        cout<<"----------------------------------------------------\n";
        
        for(int i=0; i<totitem; i++)
        {
        cout<<i+1.<<" "<<fmenu[i]<<"\t\t\t\t"<<price[i];
        cout<<"\n";
        }
        if(totitem==0)
        {
            cout<<"\nNone Food Items Specified.... ";
            
        }
    }
     
    void getredata()
    {   getchar();
        cout<<"Enter the Food Stall Name    : ";
        gets(name);
        
        cout<<"Enter the Food Stall ID      : ";
        cin>>restid;
        getchar();
        cout<<"Enter the Mobile  Number     : ";
        gets(mobile);
       
        cout<<"Enter the E-Mail ID          : ";
        gets(mail);
        
        cout<<"Enter the Stall Unique ID    : ";
        cin>>stallid;
        getchar();
        cout<<"\n Food Stall Food Options Possible are\n1.South-Indian\n2.Continental\n3. Chinese\n4.Italian\n5.Multiple";
        
        int foodtype;
        cout<<"\nEnter your choice:";
        cin>>foodtype;
        if(foodtype==1)
        {
            strcpy(retype, "South Indian");
        }
        else if(foodtype==2)
        {
            strcpy(retype,"Continental");
        }
        else if(foodtype==3)
        {
            strcpy(retype,"Chinese" );
        }
        else if(foodtype==4)
        {
            strcpy(retype,"Italian" );
        }
        else if(foodtype==5)
        {
            strcpy(retype,"Multiple" );
        }
        else
        {cout<<"Invalid entry!!";}
        cout<<"\nEnter the Total Food Menu Items : ";
        cin>>totitem;
        
        for(int i=0; i<totitem; i++)
        {   getchar();
            cout<<"Enter the Food Item "<<i+1<<" Name : ";
            gets(fmenu[i]);
            getchar();
            cout<<"Enter the Price of Food "<<i+1<<" INR : ";
            cin>>price[i];
        }
        cout<<"\nPlease note your UserName is ID i.e. "<<restid<<"\n";
    }
    void redisplay()
    {
        cout<<"\nFood Stall Name                       : "<<name;
        cout<<"\nFood Stall ID                         : "<<restid;
        cout<<"\nFood Stall Mobile No.                 : "<<mobile;
        cout<<"\nFood Stall E-Mail ID                  : "<<mail;
        cout<<"\nFood Stall Food Menu Total Items      : "<<totitem;
        cout<<"\n";
        menu();
        
    }
    
    
    int searchrebyfoodtype()
  {          cout<<"\nFood Stall Name                            : "<<name;
              cout<<"\nFood Stall ID                                  : "<<restid;
              cout<<"\nFood Stall Mobile No.                     : "<<mobile;
             cout<<"\nFood Stall E-Mail ID                         : "<<mail;
            cout<<"\nFood Stall Food Menu Total Items      : "<<totitem;
        cout<<"\n";

      if((strcmp(::ft,retype)==0))
      {
      cout<<"\n";
        menu();
    cout<<"\n";
            
        }
  else 
  return 0;
  }
  int knowremenu()
    {
        if((strcmp(::un,restid)==0))
        {
            cout<<"\nFood Stall Type : "<<retype;
            cout<<"\n";
            menu();
            
        return 1;
        }
        else 
        {
            return 0;
        }
        
    }
    
    void addremenu()
      { if(strcmp(::un,restid)==0)
           {cout<<"\nenter the new food item:";
           cin>>fmenu[totitem];
           cout<<"\nenter the price of new food item:";
           cin>>price[totitem];
           totitem++;
           cout<<"\n\n new food item added succesfully...\n";
           cout<<"Updated menu card\n";
           knowremenu();
           
           }
    }
        void delremenu()
       {  knowremenu();
          int de=0;
         if((strcmp(::un,restid)==0))
         {
            if(totitem==0 || totitem<0)
            {
            totitem=0;
            cout<<"\nnone fmenu exist";
            }
    cout<<"\nenter the Food serial no. to be deleted:";
    cin>>de;
    if(de==totitem)
    { 
        totitem--;
    strcpy(fmenu[totitem]," ");
    price[totitem]=NULL;
    }
    else if(totitem==1)
    {totitem=0;
    strcpy(fmenu[totitem]," ");
    price[0]=NULL;
    }
    else
    { de--;
    strcpy(fmenu[totitem]," ");
    for(int p=de;p<totitem;p++)
    { strcpy(fmenu[p],fmenu[p+1]);
    price[p]=price[p+1];
    }
    totitem--;
    }
    cout<<"\nrecords updated succesfully!!";
    cout<<"-----------------Updated menu-------------------- \n";
    knowremenu();
    
}
}
void modreprofile()
{ if((strcmp(::un,restid)==0))
  {
      cout<<"\n PROFILE DETAILS  \n";
      cout<<"\n1.food stall email      : "<<mail;
      cout<<"\n2.food stall mobile     : "<<mobile;
      
      int g=-1;
      cout<<"\n enter the detail no. to be modified else press 0 to exit: ";
      cin>>g;
      if(g==2)
      {char nmobile[20];
      getchar();
      cout<<"\n enter the new mobile no.:";
      gets(nmobile);
      strcpy(mobile,nmobile);
      cout<<"\n records updated succesfully";
      }
      else if(g==1)
      {char nmail[20];
      getchar();
      cout<<"\n enter new mail address:";
      gets(nmail);
      strcpy(mail,nmail);
      cout<<"\n records updated succesfully!!";}
      else if(g==0)
      cout<<"\nThank you\nRecords have been updated succesfully!!";
      else
      cout<<"invalid entry\n no such option exist";
  }
}
  int knowremenutocustomer()
  {if(strcmp(::sid,stallid)==0)
      {cout<<"\nfood stall name                        :"<<name;
       cout<<"\nfood stall unique id                   :"<<stallid;
       cout<<"\nfood stall food menu type              :"<<retype;
       cout<<"\nfood stall total food menu items       :"<<totitem;
       cout<<"\n";
        menu();
      }
  }
}a,f;
  class M:public Admin
  {
      public:
  void admin_call()
  {   int k;
      char adminuser[20],adminpass[20];
      cout<<"\nwelcome  to admin login portal\n";
      cout<<"Enter the user name     :";
      cin>>adminuser;
      cout<<"Enter the password      :";
      for(k=0;k<8;k++)
      {cin>>adminpass[k];
     }
      adminpass[k]='\0';
      
      if((strcmp(adminuser,"ADMIN")==0)&&(strcmp(adminpass,"poiuytre")==0))
        {int tmp;
           int q=1;
           cout<<"\n\t\twelcome to admin panel";
           do{
                cout<<"\n\nPress 1 to add single food stall with record";
               cout<<"\n\nPress 2 to add multiple food stalls with record";
               cout<<"\n\nPress 3 to view all food stalls with record";
               cout<<"\n\nPress 4 to Modify a food stall profile ";
               cout<<"\n\nPress 5 to Add a Food Item ";
               cout<<"\n\nPress 6 to Delete a Food Item";
               cout<<"\n\nenter your choice:";
               cin>>tmp;
               if(tmp==1)
                {cout<<"\n enter the details\n";
                fstream fs;
                fs.open("sample.txt",ios::in|ios::out|ios::ate|ios::app);
                a.getredata();
                fs.write((char *)&a,sizeof(Admin));
                fs.close();
                cout<<"\nrecord entered succesfully";
                }
                if(tmp==2)
                {int m=0;
                fstream fs;
                fs.open("sample.txt",ios::in|ios::out|ios::ate|ios::app);
                    do{
                        cout<<"\n enter the details:\n";
                        a.getredata();
                        fs.write((char *)&a,sizeof(Admin));
                        cout<<"press 0 if you want to enter more records";
                        cin>>m;
                      }while(m==0);
                     fs.close();
                cout<<"\nrecord entered successfully";
                }
                if(tmp==3)
                {fstream fs;
                 fs.open("sample.txt",ios::in);
                 fs.seekg(0);
                 while(!fs.eof())
                 {fs.read((char *)&a,sizeof(Admin));
                 if(fs.eof())
                 {break;}
                 a.redisplay();
                 
                 }
                fs.close();}
                if(tmp==4)
                 {
                 fstream fs;
                 fstream fs1;
                 cout<<"enter the unique ID of the food stall: ";
                 cin>>un;
                 fs.open("sample.txt", ios::in);
                 fs.seekg(0);
                 fs1.open("modify.txt", ios::out|ios::ate);
                 for(int i=0;i<1;i++)
                        {
                          fs.read((char *)&f, sizeof(Admin));
                          f.modreprofile();
                          
                          
                          fs1.write((char *)&f, sizeof(Admin));
                         }
                       fs.close();
                       fs1.close();
                       remove("sample.txt");
                      rename("modify.txt","sample.txt");
                      }
                      
                if(tmp==5)
                     {
                        fstream fs;
                        fstream fs1;
                        cout<<"enter the unique ID of the food stall: ";
                        cin>>un;
                        fs.open("sample.txt", ios::in);
                        fs1.open("tmpsample.txt", ios::out|ios::ate|ios::app);
                        fs.seekg(0);
                        for(int i=0;i<1;i++)
                         {    
                              fs.read((char *)&f, sizeof(Admin));
                              f.addremenu();
                              fs1.write((char *)&f, sizeof(Admin));
                         }
                        fs.close();
                        fs1.close();
                        remove("sample.txt");
                        rename("tmpsample.txt", "sample.txt");
                    }
                    
                    if(tmp==6) 
                    {
                     fstream fs;
                    fs.open("sample.txt", ios::in);
                    fstream fs1;
                    fs1.open("delsample.txt", ios::out|ios::ate|ios::app);
                    cout<<"enter the unique ID of the food stall: ";
                    cin>>un;
                    fs.seekg(0);
                    for(int i=0;i<1;i++)
                   {
                    fs.read((char *)&f, sizeof(Admin));
                    f.delremenu();
                    fs1.write((char *)&f, sizeof(Admin));
                   }
                   fs.close();
                   fs1.close();
                   remove("sample.txt");
                   rename("delsample.txt", "sample.txt");
                   }
                if(tmp<1||tmp>6)
                {cout<<"Inavlid entry\n No such option exist's";}
                
                cout<<"\n\nenter 1 for more options otherwise 0:";
                cin>>q;
                if(q==0)
                {cout<<"\t\tThank you!!!........";}
                
         }while(q==1);
         
        }
         
      else
      {cout<<"\n\n\t\tinavlid access to portal";
      cout<<"\n\n\t\t thank you";
      }
      
}


void customer_call()
    {int tmp;
           int m=0;
    do{
        cout<<"\n\n\t\t\tWelcome to customer panel   ";
        cout<<"\n\n\t\t\t\t\t\t  Guest login";
        cout<<"\n\nPress 1 to view All Food Stall/Food stall details";
        cout<<"\n\nPress 2 to search a Food Stall (Depending on taste)";
        int inchoice;
        cout<<"\n\nEnter your choice :";
        cin>>inchoice;
        if(inchoice==1)
        {
           fstream fs;
           fs.open("sample.txt", ios::in);
           fs.seekg(0);
           while(!fs.eof())
           {
               fs.read ((char *)&a, sizeof(Admin));
               if(fs.eof())
               {break;}
               a.redisplay();
           }
           fs.close();
        }
        
        if(inchoice==2)
        {

            int result;
            cout<<"\nFood Stall Food Options Possibilities are \n1.South Indian\n2.Continental\n3.Chinese\n4.Thailand\n5.Multiple";
            cout<<"\nEnter the Food Stall Food option Type(Unique Number)";
            cin>>result;
            if(result==1)
            strcpy(ft,"South Indian");
            else if(result ==2)
            strcpy(ft,"Continental");
            else if(result ==3)
            strcpy(ft,"Chinese");
            else if(result ==4)
            strcpy(ft,"Thailand");
            else
            strcpy(ft,"Multiple");
            fstream fs;
            fs.open("sample.txt", ios::in);
while(!fs.eof())
{
   fs.read((char *)&a,sizeof(Admin));
   result=a.searchrebyfoodtype();
   if(result==1)
   {
       break;
   }
}
if(result!=1)
{
    cout<<"\nNo Such Food Stall Found......";
}
}
if(inchoice<1||inchoice>2)
cout<<"\nInvalid Input Provided....";
cout<<"\n\nPress 1 otherwise 0 to Perform More Operations : ";
cin>>m;
if(m==1)
{
    
    cout<<"\n\n\n\t\tThank You!!!";
    
}
}while(m==0);

} 
    
        
     
    
}m;

int main()
{   
    int ch;
    
    cout<<"\n\n\t\t\tWelcome to Food Court Management System ";
    cout<<"\n\n\t\t\tEnter to Comtinue ";
   
    cout<<"\n\n\t\t\tPress 1 for Admin Portal";
    cout<<"\n\n\t\t\tPress 2 for Customer Portal";
    cout<<"\n\n\t\t\tEnter Your Choice : ";
    cin>>ch;
    
    if(ch==1)
    {
        m.admin_call();
        
    } 
    
    
    if(ch==2)
    {
        m.customer_call();
        
    }
    if(ch<1||ch>2)
    {
        cout<<"invalid input";
    }
    return 0;
}
