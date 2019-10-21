#include <iostream>
#include <string>
using namespace std;

#define EI >>8
#define EIR <<8
#define SI >>16
#define SIR <<16
#define TF >>24
#define TFR <<24
typedef unsigned int ui;

template <class T>
void templatedfunc(T key, int no_ints, ui* message_array,bool check, ui* arr)
{
	  if(check){ cout << "Cipher Text: " ;}
	  else{ cout << "Plain Text: " ;}//Starting to print out ciphers or plaintext
	  for(int k=0; k<no_ints; k++)
	  {
		  T co1,co2,co3,co4,key1,key2,key3,key4;
		  unsigned int Cipher=0;//This variable will be updated as loop moves forwr
		  //XOR some bytes of message index with key. Then or it with chipper while shifting it, since some bytes should be shifted.
		  if(sizeof(key)==1)
		  {
			 co1=(T) message_array[k];
			 co2=(T) (message_array[k]EI);
			 co3=(T) (message_array[k]SI);
			 co4=(T) (message_array[k]TF);
			 // this four unsigned chars(co1,co2,etc.) are bytes from one message index
			 key1=key^co1;//XOR bytes of message index with key seperately
		 	 key2=key^co2;
		 	 key3=key^co3;
		 	 key4=key^co4;
			 //fill the blanks of bytes in cipher with XORed bytes
			 Cipher=Cipher | (ui) key1 ;
			 Cipher=Cipher | (ui) (key2 EIR) ;
			 Cipher=Cipher | (ui) (key3 SIR) ;
			 Cipher=Cipher | (ui) (key4 TFR) ;
			 arr[k]=Cipher;

			 cout << Cipher << "  ";
		  }
		  /*
  This is the case for short integers. Code is copy+paste of char with a little difference. Instead of 1 byte, short is 2 bytes, therefore we do our 
  calculation with 2 Bytes long packets(2 of them).
  */
		 
		  else if(sizeof(key)==2)
		  {
			  co1=(T) message_array[k];
			 co2=(T) (message_array[k]SI);

			 key1=key^co1;
			 key2=key^co2;

			 Cipher=Cipher | (unsigned int) key1 ;
			 Cipher=Cipher | (unsigned int) (key2 SIR) ;
			 arr[k]=Cipher;

			 cout << Cipher << "  " ;

		  }
		    /*
  This is the case for integers. Code is copy+paste of char with a little difference. Instead of 1 byte, int is 4 bytes, therefore we do our 
  calculation with 4 Bytes long packets(1 of them).
  */
		  else if(sizeof(key)==4)
		  {
				 co1=(T) message_array[k];
				 key1=key^co1;
				 Cipher=Cipher | (unsigned int) key1 ;
				 arr[k]=Cipher;
		
				 cout << Cipher << "  " ;
		  }
	  }
}


int main() {
  cout << "\nJust for FYI --------------------------" << endl;
  cout << "size of unsigned char is " << sizeof(char) << endl;
  cout << "size of unsigned short is " << sizeof(short) << endl;
  cout << "size of unsigned int is " << sizeof(int) << endl;
  cout << "---------------------------------------\n\n\n";

  ui* message_array;
  ui* ciphertext;
  ui* plaintext;

  cout << "Size of the message array is ";
  ui no_ints;  cin >> no_ints;
  message_array = new ui[no_ints];
  cout << "Enter the message array integers one after another by pressing enter after each number:" << endl;
  for(int i = 0; i < no_ints; i++) {
    cin >> message_array[i];
  }
  cout << "Type of key is unsigned ";
  string key_type; //Got the key_type from user
  cin >> key_type;
  if(key_type=="char")//If type is unsinged char
  {
	  unsigned char key;
	  cout << "Enter the value of key: " << endl;
	  cin >> key;//key is an unsigned char also
	  ui* arr=new ui[no_ints];//Need to store ciphers in order to decrypt them later
	  templatedfunc(key,no_ints,message_array,true,arr);
	  cout << endl;
	  templatedfunc(key,no_ints,arr,false,arr);
  }
  /*
  This is the case for short integers. Code is copy+paste of char with a little difference. Instead of 1 byte, short is 2 bytes, therefore we do our 
  calculation with 2 Bytes long packets(2 of them).
  */
  else if (key_type=="short")
  {
	  unsigned short int key;
	  cout << "Enter the value of key: " << endl;
	  cin >> key;
	   ui* arr=new ui[no_ints];//Need to store ciphers in order to decrypt them later
	  templatedfunc(key,no_ints,message_array,true,arr);
	  cout << endl;
	  templatedfunc(key,no_ints,arr,false,arr);
  }
   
  /*
  This is the case for integers. Code is copy+paste of char with a little difference. Instead of 1 byte, int is 4 bytes, therefore we do our 
  calculation with 4 Bytes long packets(1 of them).
  */
  else if(key_type=="int")
  {
	  unsigned int key;
	  cout << "Enter the value of key: " << endl;
	  cin >> key;
	   ui* arr=new ui[no_ints];//Need to store ciphers in order to decrypt them later
	  templatedfunc(key,no_ints,message_array,true,arr);
	  cout << endl;
	  templatedfunc(key,no_ints,arr,false,arr);
  }
  else 
  {
	  cout << "Not a valid statement. I'm exiting." << endl;
  }
  //TODO: Homework 6
  /*
  unsigned int a =40012;
  unsigned int b=40000;
  cout << "sonuc: " <<unsigned int(a^b) << endl;
  */
  return 0;
}
