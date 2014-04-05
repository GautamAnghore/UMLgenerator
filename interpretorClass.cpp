#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define TRUE 1
#define FALSE 0

//////////////////////////////////////////////compile_stack///////////////////////////////////////////////
class compile_stack
{
	int data[50];
	int top;

public:
	compile_stack()
	{
		top=-1;
		for(int i=0;i<50;i++)
		{
			data[i]=0;
		}
	}
	void push(int name_index)
	{
		if(top==50)
		{
			cout<<endl<<"COMPILATION STACK OUT OF MEMORY";
		}
		else
		{
			top++;
			data[top]=name_index;
		}
	}
	int pop()
	{
		int temp=0;
		if(top==-1)
		{
			cout<<endl<<"COMPILATION STACK UNDERFLOW";
		}
		else
		{
			temp=data[top];
			data[top]=0;
			top--;
		}

		return temp;
	}
	void traverse() 
	{
		for(int i=0;i<=top;i++)
			cout<<data[i]<<endl;

	}
	void truncate()
	{
		for(int i=0;i<50;i++)
			data[i]=0;
	}
	bool is_empty()
	{
		if(top==-1)
		{
			return TRUE;
		}
		else
			return FALSE;
	}
	int current_value()
	{
		return data[top];
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////link list///////////////////////////////////////////////////
template < class T >
class name_linklist_node
{
public:
	T data;
	name_linklist_node *next,*pre;
};
template < class T >
class name_linklist
{
	name_linklist_node<T> *start,*ptr;
	T empty;
	
	// this is to return the empty character according to class type of the T 
	// we need to initialise the constructor in the T class that when provided with "" creates an empty character


public:

	int count;
	int max;

	name_linklist()
	{
		start=ptr=NULL;
		count=0;
		max=0;

	}

	name_linklist(T d)
	{
		start= new name_linklist_node<T>;
		ptr=start;
		ptr->data=d;
		ptr->pre=NULL;
		ptr->next=NULL;

		if(d.size>max)
			max=d.size();
		count=1;

	}

	name_linklist(name_linklist<T> &d)
	{
		reset();
		d.go_start();
		while(!d.reach_end())
		{
			if(start==NULL)
			{
				start=ptr=new name_linklist_node<T>;
				ptr->pre=NULL;
				ptr->next=NULL;
				ptr->data=d.go_start();
				
			}
			else
			{
				ptr->next=new name_linklist_node<T>;
				ptr->next->pre=ptr;
				ptr=ptr->next;
				ptr->next=NULL;
				ptr->data=d.go_next();	
			}
		}
		//now deep copy
		
		count=d.count;
		max=d.max;

	}

	name_linklist<T> & operator=(name_linklist<T> & d)
	{
		reset();
		d.go_start();
		cout<<"got to start"<<endl;
		while(!d.reach_end())
		{
			if(start==NULL)
			{
				start=ptr=new name_linklist_node<T>;
				ptr->pre=NULL;
				ptr->next=NULL;
				ptr->data=d.go_start();
				cout<<ptr->data;
				
			}
			else
			{
				ptr->next=new name_linklist_node<T>;
				ptr->next->pre=ptr;
				ptr=ptr->next;
				ptr->next=NULL;
				ptr->data=d.go_next();	
				cout<<ptr->data;
			}
		}
		count=d.count;
		max=d.max;
		cout<<"operator = called for "<<ptr->data<<endl;
		//return *this;
	}

	void init_list(T d)
	{
		start= new name_linklist_node<T>;
		ptr=start;
		ptr->data=d;
		ptr->pre=NULL;
		ptr->next=NULL;


		if(d.size()>max)
			max=d.size();
		count=1;
	}

	void insert(T d)
	{
		if(ptr->next=new name_linklist_node<T>)
		{
			ptr->next->pre=ptr;
			ptr=ptr->next;
			ptr->next=NULL;
			ptr->data=d;
			// we need to create a proper copy constructor of the class T


			if(d.size()>max)
				max=d.size();
			count++;
		}
		else
			cout<<endl<<"LINK LIST ERROR : COULD NOT ALLOCATE NEXT NODE";
	}
	void reset()
	{
		cout<<"reset called"<<endl;

		ptr=start=NULL;
		count=0;
		max=0;
	}
	bool reach_end()
	{
		if(ptr->next==NULL)
			return TRUE;
		else
			return FALSE;
	}
	T& go_start()
	{
		ptr=start;
		return ptr->data;
		// we need to create proper copy constructor of the class T // important note
	}
	T& go_next()
	{
		if(!reach_end())
		{
			ptr=ptr->next;
			return ptr->data;
		}
		else
			return empty;
	}
	T& go_pre()
	{
		if(ptr!=start)
		{
			ptr=ptr->pre;
			return ptr->data;
		}
		else
			return empty;
	}
	void traverse()
	{
		cout<<go_start();
		while(!reach_end())
		{
			cout<<endl;
			cout<<go_next();
		}
		ptr=start;
	}

	bool is_empty()
	{
		if(count)
			return FALSE;
		else
			return TRUE;
	}
};
// TEMPLATE SPECIALIZATION FOR INT BECAUSE OF NOT EXISTANCE OF COUNT AND MAX MEMBERS IN
template <>
class name_linklist <int>
{
	name_linklist_node<int> *start,*ptr;
	int empty;
	
	// this is to return the empty character according to class type of the T 
	// we need to initialise the constructor in the T class that when provided with "" creates an empty character


public:
	int count;
	int max;

	name_linklist()
	{
		start=ptr=NULL;
		count=0;
		max=0;

	}

	name_linklist(int d)
	{
		start= new name_linklist_node<int>;
		ptr=start;
		ptr->data=d;
		ptr->pre=NULL;
		ptr->next=NULL;

		if(d>max)
			max=d;
		count=1;

	}

	name_linklist(name_linklist<int> &d)
	{
		start=ptr=d.start;
		// not deep copy ..........
		// the list created will point the memory allocated to the supplied list before	
		count=d.count;
		max=d.max;

	}

	void init_list(int d)
	{
		start= new name_linklist_node<int>;
		ptr=start;
		ptr->data=d;
		ptr->pre=NULL;
		ptr->next=NULL;


		if(d>max)
			max=d;
		count=1;
	}

	void insert(int d)
	{
		if(ptr->next=new name_linklist_node<int>)
		{
			ptr->next->pre=ptr;
			ptr=ptr->next;
			ptr->next=NULL;
			ptr->data=d;
			// we need to create a proper copy constructor of the class T


			if(d>max)
				max=d;
			count++;
		}
		else
			cout<<endl<<"LINK LIST ERROR : COULD NOT ALLOCATE NEXT NODE";
	}
	void reset()
	{
		ptr=start=NULL;
		count=max=0;
	}
	bool reach_end()
	{
		if(ptr->next==NULL)
			return TRUE;
		else
			return FALSE;
	}
	int go_start()
	{
		ptr=start;
		return ptr->data;
		// we need to create proper copy constructor of the class T // important note
	}
	int go_next()
	{
		if(!reach_end())
		{
			ptr=ptr->next;
			return ptr->data;
		}
		else
			return empty;
	}
	int go_pre()
	{
		if(ptr!=start)
		{
			ptr=ptr->pre;
			return ptr->data;
		}
		else
			return empty;
	}
	void traverse()
	{
		cout<<go_start();
		while(!reach_end())
		{
			cout<<endl;
			cout<<go_next();
		}
		ptr=start;
	}

	bool is_empty()
	{
		if(count)
			return FALSE;
		else
			return TRUE;
	}
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////name_class//////////////////////////////////////////////////
class name_class
{
	char * name;
	name_linklist< string > data;
	name_linklist< string > function;
	name_linklist< string > inherits;
	name_linklist< string > generalise;

	int width;
	int height;
	int level;
	bool empty;

	public:

	name_class()
	{
		name=NULL;
		width=2;
		height=2;
		level=0;
		empty=TRUE;
	}

	name_class(string s)
	{
		name=NULL;
		empty=TRUE;
	}

	name_class(name_class &c)
	{
		name=new char[strlen(c.name)];
		strcpy(name,c.name);
		if(!c.data.is_empty())
		data=c.data;
		if(!c.function.is_empty())
		function=c.function;
		if(!c.inherits.is_empty())
		inherits=c.inherits;
		if(!c.generalise.is_empty())
		generalise=c.generalise;

		width=c.width;
		height=c.height;
		level=c.level;
		empty=c.empty;

	}

	name_class& operator=(name_class &c)
	{
		name=new char[strlen(c.name)];
		strcpy(name,c.name);
		if(!c.data.is_empty())
		data=c.data;
		if(!c.function.is_empty())
		function=c.function;
		if(!c.inherits.is_empty())
		inherits=c.inherits;
		if(!c.generalise.is_empty())
		generalise=c.generalise;

		width=c.width;
		height=c.height;
		level=c.level;
		empty=c.empty;
		
		return * this;
	}

	void set_name(string s)
	{
		char * temp=(char *)s.c_str();
		name=new char[strlen(temp)];
		strcpy(name,temp);
		empty=FALSE;
		if(width<strlen(name)+2)
			width=strlen(name)+2;
		height++;
	}

	void set_data(name_linklist< string > & d)
	{
		cout<<"set data called"<<endl;
		data=d;
		// used operator overloading for assignment operator
		if(width>data.max+2)
			width=data.max+2;
		height+=data.count;
	}

	void set_function(name_linklist< string > & d)
	{
		cout<<"set function called";
		function=d;
		cout<<"SUCCESSFULL"<<endl;
		if(width>function.max+2)
			width=function.max+2;
		height+=function.count;
	}

	void set_inherits(name_linklist< string > & d)
	{
		inherits=d;
		if(inherits.is_empty())
		{
			level=0;
		}
	}

	void set_generalise(name_linklist< string > & d)
	{
		generalise=d;
	}

	void set_level(int l)
	{
		level=l;
	}

	int size()
	{
		return width;
	}

	void reset()
	{
		name=NULL;
		width=2;
		height=2;
		level=0;

		data.reset();
		function.reset();
		inherits.reset();
		generalise.reset();
	}

	friend std::ostream & operator<< (std::ostream & out,name_class c);

};

std::ostream & operator<< (std::ostream & out,name_class c)
{
	out<<endl;
	out<<"NAME :";
	out<<c.name;
	out<<endl<<"DATA MEMBERS :";
	out<<endl;
	if(!c.data.is_empty())
	c.data.traverse();
	out<<endl;
	out<<"FUNCTIONS :";
	out<<endl;
	if(!c.function.is_empty())
	c.function.traverse();
	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////IDENTIFIER INDEX/////////////////////////////////////////////

#define CLASS_INDEX 11
#define NAME_INDEX 1
#define DATA_INDEX 3
#define FUNCTION_INDEX 5
#define INHEIRTS_INDEX 7
#define GENERALISE_INDEX 9
#define VALUE_INDEX 0
#define SIZE 13
//////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////COMPILER CLASS////////////////////////////////////////////////

class compiler
{
	// string to check the tags
	static string check[SIZE];
/*
		//////////////////////////////////////////////////////////////
		//	1 : <name> 												//
		//	-1: </name>												//
		//	3: <data>												//
		//	-3: </data>												//
		//	5: <function>											//
		//	-5: </function>											//
		//	7: <inherits>											//
		//	-7: </inherits>											//
		//	9: <generalise>											//
		//	-9: </generalise>										//
		//	11: <class>												//
		//	-11: </class>											//
		//	0: data 												//
		//////////////////////////////////////////////////////////////
*/
	ifstream fhandle;
	ofstream compileHandle;

	string fline;

	compile_stack manager;

	name_linklist<name_class> raw_class_list;

	int error;

	int decode(string fline)
	{
		
		for(int i=0;check[i]!= "";i++)
		{
			if(fline==check[i])
			{
				if((i%2)!=0)
				{
					return (-i);
				}
				else 
				{
					return i+1;
				}
			}
		}

		return 0;

	}


public:
	compiler(int argc,char *argv)
	{
		error=0;
		if(argc<2)
		{
			cout<<"ERROR :: FILE NAME NOT PASSED";
			error=1;
		}
		else
		{

			fhandle.open(argv,ios::in);
			if(!fhandle.is_open())
			{
				cout<<"ERROR :: FILE IS INVALID";
				error=1;
			}
			strcat(argv,".tmp");
			compileHandle.open(argv,ios::out | ios::binary);

			if(!compileHandle.is_open())
			{
				cout<<"ERROR :: COMPILATION FILE COULD NOT BE CREATED";
				error=1;
			}

			char ch=1;
			char flag=0;

			while(!fhandle.eof()&&(!error))
			{
				flag=0;
				fhandle.get(ch);

				while((ch!=10)&&(!fhandle.eof()))
				{
					if(ch!=' ')
					{
						flag=1;
						compileHandle.put(ch);
						break;
					}
					else
					{
						fhandle.get(ch);
					}
				}
				if(flag==1)
				{
					while((ch!=10)&&(!fhandle.eof()))
					{
						fhandle.get(ch);
						if(!fhandle.eof())
						{
							compileHandle.put(ch);
						}
					}
				}
				
			}
			fhandle.clear();
			compileHandle.clear();

			fhandle.close();
			compileHandle.close();

			if(!error)
			fhandle.open(argv,ios::in);

		}

	}

	~compiler()
	{
		fhandle.close();
	}


	int classify() 
	{
		name_linklist<int> visited;
		int vtemp;// for getting the data of visited nodes
		char vflag;// for holding visited or not status

		//temporary storage for class details to insert in ll
		name_class temp_class_store;
		//temporary storage for string ll
		name_linklist<string> temp_string_store;

		

		while((!fhandle.eof())&&(!error))
		{	
			getline(fhandle,fline);

			if(decode(fline)==CLASS_INDEX)
			{
				//PUSHING IN STACK
				manager.push(CLASS_INDEX);
				//PUSHING IN VISITED LIST
				visited.init_list(CLASS_INDEX);
				//NOTE : NEED TO RESET THE VISITED LL BEFORE ENCOUNTER OF NEXT CLASS

				int case_control=CLASS_INDEX;
				int index;

				while((!manager.is_empty())&&(!fhandle.eof())&&(!error))
				{
					getline(fhandle,fline);
					case_control=decode(fline);
					
					switch (case_control)
					{
						case NAME_INDEX:// class name
									
										vtemp=visited.go_start();
										vflag=0;//FLAG 0 MEANS NOT VISITED // FLAG 1 MEANS VISITED
										while(!visited.reach_end())
										{
											if(vtemp==NAME_INDEX)
											{
												vflag=1;
												break;
											}
											else
												vtemp=visited.go_next();

										}
										if(vflag==0)
										{
											manager.push(NAME_INDEX);
											visited.insert(NAME_INDEX);
											while((manager.current_value()!=CLASS_INDEX)&&(!error))
											{
												getline(fhandle,fline);
												if(decode(fline)==0)
												{
													temp_class_store.set_name(fline);
													getline(fhandle,fline);
													if(decode(fline)==0)
													{
														cout<<"ERROR : two names not possible inside <name>";
														error=1;
														break;

													}
													else if(decode(fline)==-NAME_INDEX)
													{
														manager.pop();
														break;
													}
													else
													{
														cout<<"ERROR : <name> not properly closed";
														error=1;
														break;
													}

												}
												else
												{
													cout<<"ERROR : <name> not properly closed";
													error=1;
													break;
												}

											}
										}
										else
										{
											cout<<"ERROR : <name> used more than once in one class";
											error=1;
											break;
										}
									
										break;

						case DATA_INDEX:
						case FUNCTION_INDEX:
						case INHEIRTS_INDEX:
						case GENERALISE_INDEX:// all have the same method to store in link list 
										
											index=case_control;

											vtemp=visited.go_start();
											vflag=0;
											while(!visited.reach_end())
											{
												if(vtemp==index)
												{
													vflag=1;
													break;
												}
												else
													vtemp=visited.go_next();

											}
											if(vflag==0)
											{
												manager.push(index);
												visited.insert(index);
												while((manager.current_value()!=CLASS_INDEX)&&(!error))
												{
													getline(fhandle,fline);
													if(decode(fline)==0)
													{
														if(temp_string_store.is_empty())
														{
															temp_string_store.init_list(fline);
														}
														else
														{
															temp_string_store.insert(fline);
														}

													}
													else if(decode(fline)==-index)
													{
														int pop;
														pop=manager.pop();
														cout<<endl<<manager.current_value()<<endl;
														if(pop!=index)
														{
															cout<<"ERROR : UNDETERMINED DATA IN COMPILATION STACK";
															error=1;
														}
														//if(temp_string_store.is_empty())
														{
															switch (index)
															{
																case DATA_INDEX:
																				temp_class_store.set_data(temp_string_store);
																				cout<<"data set";
																				break;
																case FUNCTION_INDEX:
																				temp_class_store.set_function(temp_string_store);
																				cout<<"fun set";
																				break;
																case INHEIRTS_INDEX:
																				temp_class_store.set_inherits(temp_string_store);
																				break;
																case GENERALISE_INDEX:
																				temp_class_store.set_generalise(temp_string_store);
																				break;
															}
															temp_string_store.reset();
														}
														break;
													}
													else
													{
														cout<<"ERROR : "<<check[index-1]<<" not properly closed";
														error=1;
														break;
													}

												}
											}
											
											else
											{
												cout<<"ERROR :"<<check[index-1]<<" used more than once in one class";
												error=1;
												break;
											}
										
										break;
						
						case VALUE_INDEX:
										cout<<endl<<"ERROR : DATA NOT MARKED UP PROPERLY : USE TAGS TO WRAP THE DATA :";
										error=1;
										break;
						case -DATA_INDEX:
						case -FUNCTION_INDEX:
						case -INHEIRTS_INDEX:
						case -GENERALISE_INDEX:
											index=(-case_control);
											cout<<endl<<"ERROR : EXPECTED "<<check[(index-1)]<<" BEFORE "<<check[index];
											error=1;
											break;
						case -CLASS_INDEX:
										
											visited.reset();
											manager.pop();
											
											if(raw_class_list.is_empty())
											{
												raw_class_list.init_list(temp_class_store);
											}
											else
											{
												raw_class_list.insert(temp_class_store);
											}

											temp_class_store.reset();

											
										break;

					}
					

				}
			}
			else
			{
				cout<<endl<<"ERROR : <class> NOT FOUND";
			}
			
		}
	
		return error;

	}

	void traverse_class_linklist()
	{
		raw_class_list.traverse();
	}

};

string compiler::check[]={"<name>","</name>","<data>","</data>","<function>","</function>","<inherits>","</inherits>","<generalise>","</generalise>","<class>","</class>",""};

int main(int argc,char *argv[])
{
	
	compiler c(argc,argv[1]);

	if(!c.classify())
	{
		cout<<endl<<endl;
		cout<<"COMPILATION SUCCESSFULL :"<<endl;
		c.traverse_class_linklist();

	}
	else
	{
		cout<<endl;
		cout<<"COMPILATION FAILURE : TERMINATING";
		cout<<endl;
	}
	

	return 0;
}

