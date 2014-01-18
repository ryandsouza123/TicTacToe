#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

// class to describe each move
class move{ 

	private: int row;
		 int col;
		 char type;	

	public: int getrow(){return row;}
		int getcol(){return col;}
		char gettype(){return type;}
		void putrow(int r){row = r;}
		void putcol(int c){col = c;}
		void puttype(char c){type = c;}
};

// class template for the game board
class board
{

		int nrow;
		int ncol;
		move mv[10][10]; 

	public: void maxcont();
		board(int r,int c);
		int checkboard();
		void addmove(move);
		int check(move);
		void drawresult(int,int,char);
};



board::board(int nro,int nco)
{

	this->nrow = nro+1;
	this->ncol = nco+1;

	int i =0;
	int j =0;
	char c =' ';

	for(i=1;i<nrow;i++)
  		for(j=1;j<ncol;j++)
  		{
	 		mv[i][j].putrow(i);	
	 		mv[i][j].putcol(j);
		        mv[i][j].puttype(c);
	        } 
}

int board::check(move m)
{
	if(mv[m.getrow()][m.getcol()].gettype() == ' ')
		return 1;
	else
		return 0;


}



void board::addmove(move m)
{
   	int i = m.getrow();
   	int j = m.getcol();
   	mv[i][j] = m;	
}

void board::drawresult(int m, int opt,char ch)
{	int i;
	int j;
	int mrow = 1;
	int mcol = ncol-1;
	char inbet[2];
	char colbet[3];
	char colendbet[3];

	cout << string(50, '\n');
	cout<<"====================================================="<<endl;
	cout<<" Tic Tac Toe"<<endl<<endl<<endl<<endl;
	cout<<"the winner is "<< ch<<endl;
	for(i=1;i<nrow;i++){
  		for(j=1;j<ncol;j++)
 	 	{  	
	        	if(opt == 1 && (i == m) ) 
				 strcpy(inbet, "-");
		        else if(opt == 4 && (j == mcol) && (i == mrow))
				 strcpy(inbet, "/");
		 	else 
				 strcpy(inbet, " "); 
		
		
		
			if(j != (ncol-1))	
					cout<<mv[i][j].gettype()<<inbet<<"|";
			else
				
					cout<<mv[i][j].gettype()<<inbet<<endl;
  	      }	
			if(i!=(nrow-1))
			{
				int k;		
				for(k = 1;k<ncol-1;k++)
					if(opt == 2 && (k == m) ) 
						cout<<"|_"<<"|";
					else if(opt == 3 && (k == i) ) 
						cout<<"_\\"<<"|";
					else if(opt == 4 && (k == mcol) && (i == mrow)) 
					{
						cout<<"/_"<<"|";
				 		mcol--; mrow++; 	
					}
					else
						cout<<"__"<<"|";
			
			
					if(opt == 2 && (k == m) ) 
						cout<<"|_"<<endl;
					else if(opt == 3 && (k == i) ) 
						cout<<"_\\"<<endl;
					else if(opt == 4 && (k == mcol) && (i == mrow)) 
					{
						cout<<"/_"<<endl;
				 		mcol--; mrow++;
					}	
					else
						cout<<"__"<<endl;
			
		      }
	
		
	}
	int k;
	for(k = 1;k<ncol-1;k++)
	{
		if(opt == 2 && (k == m) ) 
			cout<<"| "<<"|";
		else if(opt == 3 && (k == i-1) ) 
			cout<<" \\"<<"|";
		else if(opt == 4 && (k == mcol) && (i-1 == mrow)) 
			{
				cout<<"/ "<<"|";
				mcol--; mrow++;
			}	
		else
				cout<<"  "<<"|";
	}
	if(opt == 2 && (k == m) ) 
		cout<<"| "<<endl;
	else if(opt == 3 && (k == i-1) ) 
		cout<<" \\"<<endl;
	else if(opt == 4 && (k == mcol) && (i-1 == mrow)) 
		{
			cout<<"/ ";
			mcol--; mrow++;}	
	else
			cout<<"  "<<endl;
			
		
	cout<<endl;	


}

int board::checkboard()
{
  	int i =0;
  	int j =0;
  	char c;
  	int x = 1;
  	int y	= 1;
  	int flag = 0;	
	
		for(i=1;i<nrow;i++)
  			for(j=1;j<ncol;j++)
				if(mv[i][j].gettype() == ' ')
					flag = 1;
		
	
	cout << string(50, '\n');
	cout<<"====================================================="<<endl;	
	cout<<" Tic Tac Toe"<<endl<<endl<<endl<<endl;
	
	for(i=1;i<nrow;i++)
	{
  		for(j=1;j<ncol;j++)
 	 	{
			if(j != (ncol-1))	
					cout<<mv[i][j].gettype()<<" "<<"|";
			else
			
					cout<<mv[i][j].gettype()<<" "<<endl;
  		}	
		if(i!=(nrow-1)){
			for(int k = 0;k<ncol-2;k++)
				cout<<"__"<<"|";
				cout<<"__"<<endl;}
	}
		for(int k = 0;k<ncol-2;k++)
				cout<<"  "<<"|";
				cout<<"  "<<endl;
				cout<<endl;	




	//row check
	j=1;
	for(i=1;i<nrow;i++)
	{
		if((c = mv[i][j].gettype()) != ' ')
		{
			int sum = 0;
			j=1;
	
			 while(mv[i][j].gettype() == c && j<ncol)
				{
					sum++;j++;
				}
		
			if(sum == ncol-1)
				{
					cout<<"the winner is "<< c<<endl;
					drawresult(i,1,c);			
					return 1;
				}
		}
	}

	//col check	
	i=1;
	for(j=1;j<ncol;j++)
	{
		if((c = mv[i][j].gettype()) != ' ')
		{
			int sum = 0;
			i=1;
	
		 	while(mv[i][j].gettype() == c && i<nrow)
			{	
				sum++;i++;  
			}
		
			if(sum == nrow-1)
			{
				cout<<"the winner is "<< c<<endl;
				drawresult(j,2,c);
				return 1;
			}
	       }
      }



      	//checking across top left to bottom right	
      	if((c = mv[1][1].gettype()) != ' ')
      	{	
		int sum = 0;

		for(i=1,j=1;i<nrow;i++,j++)		
		{
			if(mv[i][j].gettype() == c)
				sum++;
		}
		if(sum == nrow-1)
		{
			cout<<"the winner is "<< c<<endl;
			drawresult(i,3,c);
			return 1;
		}

	}

	//checking across top right to bottom left
	if((c = mv[1][ncol-1].gettype()) != ' ')
	{
		int sum = 0;
	
		for(i=1,j=ncol-1;i<nrow;i++,j--)		
		{
			if(mv[i][j].gettype() == c)
				sum++;
		}
		if(sum == nrow-1)
		{
			cout<<"the winner is "<< c<<endl;
			drawresult(i,4,c);
			return 1 ;
		}

	}
	
	if(flag == 0)
	{ 
		cout<<"Draw !!"<<endl;	
 	        return 1;	
	}
	




	return 0;
}

int main()
{

	int r,c;
	cout << string(50, '\n');
	cout<<"====================================================="<<endl;
	cout<<" Tic Tac Toe"<<endl<<endl<<endl<<endl;
	cout<<endl<<endl;
	r=3;
	char* input;
		do{
			cout<<"enter the no of rows and colums (max 9) (min 1) ";
			cin>>input;

			if(strlen(input) == 1)
			{
				if(input[0]-'0' < 9 && input[0]-'0' > 1)
				{
					r= input[0]-'0';
					break;
				}
			}

		 }while(1);
		 c=r;


	board* obj = new board(r,c);
	obj->checkboard();

	char str[10];
	int opt = 0;
	char ch = 'X';	
	int cnt = 0;
	char choice;

	while(1)
	{
		cout<< "Player \""<<ch<<"\" Enter the next move \" Row,Column \" or Type \" exit \"  to leave or \"retry\" to restart  ";
		cin>>str;
		if(((str[0]-'0'>0) && (str[0]-'0'<r+1)) && ((str[2]-'0'>0) && (str[2]-'0'<c+1)) && (str[1] == ','))
		{
			move m;
			m.putrow(str[0]-'0');
			m.putcol(str[2]-'0');
			m.puttype(ch);

			if(obj->check(m))
			{
				obj->addmove(m);
				if(obj->checkboard() == 1)
				{
					do
					{
						cout<<"Play new game ? (Y/N) ";
						cin>>choice;
					}while(choice != 'Y' && choice != 'N');
					
					if(choice == 'Y')
					{	
						cout << string(50, '\n');
						cout<<"====================================================="<<endl;
						cout<<" Tic Tac Toe"<<endl<<endl<<endl<<endl;
						cout<<endl<<endl;
						r=3;

						do
						{
							cout<<"enter the no of rows and colums (max 9) (min 2) ";
							cin>>input;

							if(strlen(input) == 1)
							{
								if(input[0]-'0' <=9 && input[0]-'0' > 1)
								{
									r= input[0]-'0';break;
								}

							}

						}while(1);
						c=r;
						obj = new board(r,c);
						obj->checkboard();
			  
				}	
		else
		{
			break;   
		} 
	}
		if(cnt%2 == 0)
		{
			ch = '0';cnt++;
		}
		else
		{
			ch = 'X';cnt++;
		}
	}
	else
	{
		cout<< "Invalid Entry"<<endl<<"there is already an entry here"<<endl;
	}



	}
	else if(strcmp(str,"retry")==0)
	{
		cout << string(50, '\n');
		cout<<"====================================================="<<endl;
		cout<<" Tic Tac Toe"<<endl<<endl<<endl<<endl;
		cout<<endl<<endl;
		r=3;

		do{
			cout<<"enter the no of rows and colums (max 9) (min 2) ";
			cin>>input;

			if(strlen(input) == 1)
			{
				if(input[0]-'0' <= 9 && input[0]-'0' > 1)
				{
					r= input[0]-'0';break;
				}

			}

		  }while(1);

		  c=r;
		  obj = new board(r,c);
		  obj->checkboard();

}
	else if(strcmp(str,"exit")==0)
	{
 		break;
	}
	else
	{
		cout<< "Invalid Entry \" Row,Column \""<<endl;}
	}




	free(obj);
	return  1;
}
