#include<iostream> 
#include<string>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;

void Interface();//主界面函数 
int ChooseWordList();//选择课程函数 
void ChooseTestWay();//选择测试方式函数 
void RecordRecitedWord();//记录已背单词函数 
int goback;//全局变量 //返回上一级的功能 
int lesson_order;//课程序号 
int way;//测试方式 

//six word list file
	ifstream BandFourWordFile;//四级词汇文件 
	ifstream BandSixWordFile;//六级词汇文件 
	ifstream TOEFLWordFile;//托福词汇文件
	ifstream IELTSWordFile;//雅思词汇文件 
	fstream RecitedWordFile;//已背词汇文件 
	fstream PersonalWordFile;//个人词库文件 

class WordList{//基类 
	public:
		friend void ShowEnglish(int lesson_order);//显示英文 
		friend void ShowChinese(int lesson_order);//显示中文 
		friend void Interface();//将子函数，主界面函数设为友元函数 
		string word_english;//词汇的英文 
		string word_chinese;//词汇的中文	
};

	WordList RecitedWordList1;//基类定义的已背词汇表对象 

class PersonalWordList:public WordList{//派生类 
	public:
		void EditWordList();//编辑个人词库函数 
		void AddWord();//添加词汇函数 
		void BrowseWord();//浏览个人词汇函数 
		friend class PublicWordList;//将另一个派生类设为友元类 
		friend void Interface();  //主界面函数作为友元函数
};

	PersonalWordList PersonalWordList1;//派生类即个人词汇类定义的对象 
	
class PublicWordList:public WordList{//派生类
	public:
		friend void ShowEnglish(int lesson_order);
		friend void ShowChinese(int lesson_order);
		friend void ChooseTestWay();//选择测试方式（显示英文还是显示中文） 
		friend int ChooseWordList();//选择要测试的课程（包括四个公共词库） 
		friend class PersonalWordList;
		friend void Interface(); //主界面函数作为友元函数
};

//four object under the class of PublicWordList
	PublicWordList BandFourWordList1;
	PublicWordList BandSixWordList1;
	PublicWordList TOEFLWordList1;
	PublicWordList IELTSWordList1;
	

	string answer_chinese;//用户回答的中文
	string answer_english; //用户回答的英文
void ShowChinese(int lesson_order)
{
	if(lesson_order==1)
	{
		BandFourWordFile.open("file_BandFourWord.txt",ios::in);
		if(BandFourWordFile.good())
		{
			BandFourWordFile>>BandFourWordList1.word_english;
			BandFourWordFile>>BandFourWordList1.word_chinese;
		} 
		cout<<BandFourWordList1.word_chinese<<endl;
		BandFourWordFile.close();
	}
	else if(lesson_order==2)
	{
		BandFourWordFile.open("file_BandSixWord.txt",ios::in);
		if(BandSixWordFile.good())
		{
			BandFourWordFile>>BandSixWordList1.word_english;
			BandFourWordFile>>BandSixWordList1.word_chinese;
		}
		cout<<BandSixWordList1.word_chinese<<endl;
		BandSixWordFile.close();
	}
	else if(lesson_order==3)
	{
		IELTSWordFile.open("file_IELTSWord.txt",ios::in);
		if(IELTSWordFile.good())
		{
			IELTSWordFile>>IELTSWordList1.word_english;
			IELTSWordFile>>IELTSWordList1.word_chinese;
		}
		cout<<IELTSWordList1.word_chinese<<endl;
		IELTSWordFile.close();
	}
	else //lesson_order==4
	{
		TOEFLWordFile.open("file_TOEFLWord.txt",ios::in);
		if(TOEFLWordFile.good())
		{
			TOEFLWordFile>>TOEFLWordList1.word_english;
			TOEFLWordFile>>TOEFLWordList1.word_chinese;
		}
		cout<<TOEFLWordList1.word_chinese<<endl;
		TOEFLWordFile.close();
	}
	
}
void ShowEnglish(int lesson_order)
{
	if(lesson_order==1)
	{
		BandFourWordFile.open("file_BandFourWord.txt",ios::in);
		if(BandFourWordFile.good())
		{
			BandFourWordFile>>BandFourWordList1.word_english;
			BandFourWordFile>>BandFourWordList1.word_chinese;
		}
		cout<<BandFourWordList1.word_english<<endl;
		BandFourWordFile.close();
	}
	else if(lesson_order==2)
	{
		BandSixWordFile.open("file_BandSixWord.txt",ios::in);
		if(BandSixWordFile.good())
		{
			BandFourWordFile>>BandSixWordList1.word_english;
			BandFourWordFile>>BandSixWordList1.word_chinese;
		}
		cout<<BandSixWordList1.word_english<<endl;
		BandSixWordFile.close();
	}
	else if(lesson_order==3)
	{
		IELTSWordFile.open("file_IELTSWord.txt",ios::in);
		if(IELTSWordFile.good())
		{
			IELTSWordFile>>IELTSWordList1.word_english;
			IELTSWordFile>>IELTSWordList1.word_chinese;
		}
		cout<<IELTSWordList1.word_english<<endl;
		IELTSWordFile.close();
	}
	else //lesson_order==4
	{
		TOEFLWordFile.open("file_TOEFLWord.txt",ios::in);
		if(TOEFLWordFile.good())
		{
			TOEFLWordFile>>TOEFLWordList1.word_english;
			TOEFLWordFile>>TOEFLWordList1.word_chinese;
		}
		cout<<TOEFLWordList1.word_english<<endl;
		TOEFLWordFile.close();
	}
	
}
void PersonalWordList::EditWordList()
{
	int i;
	int m;
	for(i=1;i<=6;i++)
	{
		cout<<" "<<endl;
	}
	cout<<"--------------------------------------------------------------------------------"<<endl;
 	cout<<"         	添加单词到个人词库,      请按 1           "<<endl;
 	cout<<"              	查看个人词库,           请按 2            "<<endl;
 	cout<<"              	返回,          	        请按 0             "<<endl;
 	cout<<"--------------------------------------------------------------------------------"<<endl;
 	cin>>m;
 	system("cls");
	switch(m)
	{
		case 1:PersonalWordList1.AddWord();break;
		case 2:PersonalWordList1.BrowseWord();break;
		case 0:Interface();break; 
		default:break;	
	}
}
//the definition of addword function
void PersonalWordList::AddWord()
{
	int i; 
	cout<<"****			  添加单词到个人词库			   ****"<<endl; 
	cout<<"****			  输入添加词语的英文和中文		   ****"<<endl;
	PersonalWordFile.open("file_PersonalWord.txt",ios::app);
	cin>>PersonalWordList1.word_english>>PersonalWordList1.word_chinese;
	PersonalWordFile<<PersonalWordList1.word_english<<endl;
	PersonalWordFile<<PersonalWordList1.word_chinese<<endl;
	PersonalWordFile.close();
	system("cls");
	cout<<"****添加成功****"<<endl;
	cout<<"继续添加，请按1"<<endl;
	cout<<"返回，    请按0"<<endl; 
	cin>>i;
	system("cls");
	if(i==1)
	{
		PersonalWordList1.AddWord();
	}
	else
	{
		PersonalWordList1.EditWordList();
	}
}

void PersonalWordList::BrowseWord()
{
	PersonalWordFile.open("file_PersonalWord.txt",ios::in);
	while(PersonalWordFile.good())
	{
		PersonalWordFile>>PersonalWordList1.word_english;
		PersonalWordFile>>PersonalWordList1.word_chinese;
		cout<<PersonalWordList1.word_english<<endl;
		cout<<PersonalWordList1.word_chinese<<endl;
	}
	cin.get();
	cout<<"****    		返回上一级,请按0			****"<<endl;
	cin>>goback;
	system("cls");
	if(goback==0)
	{
		PersonalWordFile.close();
		PersonalWordList1.EditWordList();		
	}
	
}

//the definition of showchinese when user answer the meaning
void Test()
{
	int time_answer;
	
	//user can answer no more than three times
	for(time_answer=1;time_answer<=4;time_answer++)
	{
		cout<<"****请输入该词的意思****"<<endl;
		cout<<"       返回 输入 0       "<<endl; 
		//cout<<BandFourWordList1.word_english<<endl;
		if(way==1)
		{
			ShowEnglish(lesson_order);
			cin>>answer_chinese;
			if(answer_chinese==BandFourWordList1.word_chinese) 
			{
				if(time_answer==1)//user answer correctly in three times
				{
					system("cls");
					cout<<"****优秀！****"<<endl; 
					cout<<"       返回 输入 0       "<<endl;
					//ChooseTestWay(); 
					RecordRecitedWord();
				}
				else if(time_answer==2)
				{
					system("cls");
					cout<<"****干得好！****"<<endl; 
					RecordRecitedWord();
				}
				else //time_answer==3
				{
					system("cls");
					cout<<"****不错!****"<<endl;
					RecordRecitedWord();
				}
				break;
			}
			else if(answer_chinese=="0") 
			{
				system("cls");
				ChooseTestWay(); 
			}
			else
			{
				if(time_answer==1)
				{
					system("cls");
					cout<<"****		加油！再尝试！		****"<<endl;
				}
				else if(time_answer==2)
				{
					system("cls");
					cout<<"****			坚持！很快就会成功！		****"<<endl;
				}
				else if(time_answer==3)
				{
					system("cls");
					cout<<"****		再尝试一次！你会赢得战斗！		****"<<endl;
				}
				else
				{
					system("cls");
					cout<<"****		你已经回答三次了，正确答案如下		****"<<endl;
					cout<<" 返回上一级  按0"<<endl;
					cout<<BandFourWordList1.word_chinese<<endl;	
				}
			}
		}
		else
		{
			ShowChinese(lesson_order);
			cin>>answer_english;
			if(answer_english==BandFourWordList1.word_english) 
			{
				if(time_answer==1)//user answer correctly in three times
				{
					system("cls");
					cout<<"****优秀！****"<<endl; 
					RecordRecitedWord();
				}
				else if(time_answer==2)
				{
					system("cls");
					cout<<"****干得好！****"<<endl;
					RecordRecitedWord();
				}
				else //time_answer==3
				{
					system("cls");
					cout<<"****不错!****"<<endl;
					RecordRecitedWord();
				}
				break;
			}
			else if(answer_english=="0") 
			{
				system("cls");
				ChooseTestWay(); 
			}
			else
			{
				if(time_answer==1)
				{
					system("cls");
					cout<<"****		加油！再尝试！		****"<<endl;
				}
				else if(time_answer==2)
				{
					system("cls");
					cout<<"****			坚持！很快就会成功！		****"<<endl;
				}
				else if(time_answer==3)
				{
					system("cls");
					cout<<"****		再尝试一次！你会赢得战斗！		****"<<endl;
				}
				else
				{
					system("cls");
					cout<<"****		你已经回答三次了，正确答案如下		****"<<endl;
					cout<<BandFourWordList1.word_english<<endl;	
				}
			}	
		}	
	}
	ChooseTestWay();
	system("cls");		
} 
void  ChooseTestWay()//选择测试方式函数 
{
	int i;
	int way;
	for(i=1;i<=6;i++)
	{
		cout<<" "<<endl;
	}
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"	****    		请选择背单词的方式 		****"<<endl;
	cout<<"	****   	显示中文,回答英文意思  请按 1    		****"<<endl;
	cout<<"	****   显示英文,回答中文意思  请按 2  			****"<<endl;
	cout<<"	****           返回,          请按 0    		****"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cin>>way;
	system("cls");
	switch(way)
	{
		case 1: ShowChinese(ChooseWordList());break;
		case 2: ShowEnglish(ChooseWordList());break;
		case 0: Interface();break;
		default:break;
	} 	
 } 
 
 int ChooseWordList()//选择测试课程 
 {
 	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"   			选择亲想测试的课程:   			"<<endl;
	cout<<"          		BandFourWord 1                 "<<endl;
	cout<<"          		BandsixWord  2                 "<<endl;
	cout<<"          		IELTSWord    3                 "<<endl;
	cout<<"          		TOEFLWord    4                 "<<endl;
	cout<<"      	 		返回，请按 0                   "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
 	cin>>lesson_order;
 }
 
 void RecordRecitedWord()//记录已背词汇函数
 {
 	RecitedWordFile.open("file_RecitedWord.txt",ios::app);
	RecitedWordList1.word_english=BandFourWordList1.word_english;
	RecitedWordList1.word_chinese=BandFourWordList1.word_chinese;
	RecitedWordFile<<RecitedWordList1.word_english<<endl;
	RecitedWordFile<<RecitedWordList1.word_chinese<<endl;
	RecitedWordFile.close();
 }

void Interface()//the interface of this software//一级界面 
{
	int s=0;
	int i;
	
	cout<<" "<<endl;
	cout<<" 															"<<endl;
	//include the function of add and delete word//词库编辑维护 （包括添加和删除） 
	cout<<"	          		维护个人词库，请按 1         "<<endl;//personal word here
	
	cout<<" 															"<<endl;
	cout<<" 															"<<endl;
	//user can preview all words//课程预览
	cout<<"	          		预览课程，请按 2         "<<endl;//public lesson here 
	
	cout<<" 															"<<endl;
	cout<<" 															"<<endl;
	
	//user can recite word,and user should choose the way to recite words//背单词（包括两种方法）	
	cout<<"	         		开始测试 ，请按 3        "<<endl;
	
	cout<<" 															"<<endl;
	cout<<" 															"<<endl;
	
	
	cout<<"	         		查看成绩,  请按  4        "<<endl;
	cout<<" 															"<<endl;
	
	cin>>s;
	system("cls");
	if(s==1)//EditlWord()//二级界面 1
	{
		PersonalWordList1.EditWordList();
	}
	else if(s==2)//PriviewLesson()//二级界面 2
	{
		previewlesson:
		int lesson_order;
		for(i=1;i<=6;i++)
		{
			cout<<" "<<endl;
		}
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"    			选择亲想预览的课程:   			"<<endl;
		cout<<"          			BandFourWord 1                 "<<endl;
		cout<<"          			BandsixWord  2                 "<<endl;
		cout<<"          			IELTSWord    3                 "<<endl;
		cout<<"          			TOEFLWord    4                 "<<endl;
		cout<<"      	 			 返回，请按 0                   "<<endl;
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cin>>lesson_order;
		system("cls");
		if(lesson_order==1)
		{
			BandFourWordFile.open("file_BandFourWord.txt",ios::in);
			while(BandFourWordFile.good())
			{
				BandFourWordFile>>BandFourWordList1.word_english;
				BandFourWordFile>>BandFourWordList1.word_chinese;
				cout<<BandFourWordList1.word_english<<endl;
				cout<<BandFourWordList1.word_chinese<<endl;
			}
			cin.get();
			cout<<"****    		返回上一级,请按0			****"<<endl;
			cin>>goback;
			system("cls");
			if(goback==0)
			{
				goto previewlesson;				
			}
			BandFourWordFile.close();
		}
		else if(lesson_order==2)
		{
			BandSixWordFile.open("file_BandSixWord.txt",ios::in);
			while(!BandSixWordFile.eof())
			{
				BandSixWordFile>>BandSixWordList1.word_english;
				BandSixWordFile>>BandSixWordList1.word_chinese;
				cout<<BandSixWordList1.word_english<<endl;
				cout<<BandSixWordList1.word_chinese<<endl;	
			}
			cin.get();
			cout<<"****    		返回上一级,请按0			****"<<endl;
			cin>>goback;
			system("cls");
			if(goback==0)
			{
				goto previewlesson;				
			}
			BandSixWordFile.close();
		}
		else if(lesson_order==3)
		{
			IELTSWordFile.open("file_IELTSWord.txt",ios::in);
			while(IELTSWordFile.good())
			{
				IELTSWordFile>>IELTSWordList1.word_english;
				IELTSWordFile>>IELTSWordList1.word_chinese;
				cout<<IELTSWordList1.word_english<<endl;
				cout<<IELTSWordList1.word_chinese<<endl;
			}
			cin.get();
			cout<<"****    		返回上一级,请按0			****"<<endl;
			cin>>goback;
			system("cls");
			if(goback==0)
			{
				goto previewlesson;				
			}
			IELTSWordFile.close();
		}
		else if(lesson_order==4)
		{
			TOEFLWordFile.open("file_TOEFLWord.txt",ios::in);
			while(TOEFLWordFile.good())
			{
				TOEFLWordFile>>TOEFLWordList1.word_english;
				TOEFLWordFile>>TOEFLWordList1.word_chinese;
				cout<<TOEFLWordList1.word_english<<endl;
				cout<<TOEFLWordList1.word_chinese<<endl;
			}
			cin.get();
			cout<<"****    		返回上一级,请按0			****"<<endl;
			cin>>goback;
			system("cls");
			if(goback==0)
			{
				goto previewlesson;				
			}
			TOEFLWordFile.close();
		}
		else
		{
			Interface();
		}
		system("cls");	
	}
	else if(s==3)//ReciteWord()//二级界面 3
	{
		ChooseTestWay();
		system("cls");
		Test();
		cout<<"********"<<endl;
	}
	else//SeeRecitedWord//二级界面 4
	{
		cout<<"****已背单词如下：****"<<endl; 
		RecitedWordFile.open("file_RecitedWord.txt",ios::in);
		while(RecitedWordFile.good())
		{
			RecitedWordFile>>RecitedWordList1.word_english;
			RecitedWordFile>>RecitedWordList1.word_chinese;
			cout<<RecitedWordList1.word_english<<endl;
			cout<<RecitedWordList1.word_chinese<<endl;
		}
		RecitedWordFile.close();
		cin.get();
		cout<<"****    		返回上一级,请按0			****"<<endl;
		cin>>goback;
		system("cls");
		if(goback==0)
		{
			Interface();				
		}
		RecitedWordFile.close();	
	}
 } 
int main()    
{
	Interface();
	return 0; 
}
