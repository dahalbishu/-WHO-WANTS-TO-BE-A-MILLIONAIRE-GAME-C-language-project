#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <MMsystem.h>
#include <conio.h>

int initialtime,finaltime;

void lifeline1(char *ques[],char*ans[],char right[],char *description[],int a,int lifescr);
void lifeline2(char *ques[],char*ans[],char right[],char *description[],int a,int lifescr);
void lifeline3(char *ques[],char*ans[],char right[],char *description[],int a,int lifescr);
void solution_calculation(char *ques[],char*ans[],char right[],char *description[]);
void  ques1();
void  ques2();
void  ques3();
void  ques4();
void  ques5();
void  ques6();
void  ques7();
void  ques8();
void  ques9();
void  ques10();
void  ques11();
void  ques12();
void  ques13();
void  ques14();
void  ques15();
struct personal_detail {
   char	name[50];
   int age;
   char email[50];
   int score;
}person;

/* ------------ file saving ----------------------- */
 void saving()
 {
    FILE *fpointer = fopen("ScoreList.txt","a");
    fprintf(fpointer, "\n\nPlayer's Name: %s",person.name);
    fprintf(fpointer, "\nPlayer's Age: %d",person.age);
    fprintf(fpointer, "\nPlayer's Email: %s",person.email);
    fprintf(fpointer, "\nYou Won: $%d",person.score);
    fprintf(fpointer, "\n__________________________________________");
    fclose(fpointer); 
 }
   
 /* ------- final report card----------- */
void score()
{
	
	int timediff,min,sec;
    time_t finaltime; 
    finaltime = time(NULL); 
    
    timediff = finaltime-initialtime;
    min = timediff/60;
    sec = timediff%60;
    getche;
    system("cls");
    printf("\n>>>>>>>>>>YOUR PROGRESS<<<<<<<<<<\n\n");
    printf("Player's Name: %s",person.name);
    printf("\nPlayer's Age: %d",person.age);
    printf("\nPlayer's Email: %s",person.email);
    printf("\nYou Won: $%d",person.score);
    printf("\nTotal Time taken is  %d min and %d sec",min,sec);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\outro.wav",NULL, SND_SYNC);
    printf("\n\n\n>>>>>>>>>>THANK YOU FOR PLAYING THIS GAME.<<<<<<<<<<");
    saving();
    printf("\nPress any Key to Exit.");
    getch();
    exit(EXIT_FAILURE);
}

void person_info (){
	int a,b,c,emlen,check_1 =0,check_2 = 0,check_3 = 0,emcheck1 =0,emcheck2=0;
	printf("\nEnter your Full name \t:");
	gets(person.name);

    printf("\n\nEnter your Age \t:");
    scanf("%d",&person.age);
    fflush(stdin);
    printf("\n\nEnter your Email Address \t:");
    gets(person.email);

    /* Group: 1for checking the validation of entered information*/

    /* Sub group: 1.1 for checking name validation */




    /*Article:1.1.1 for allowing user to input fname,middlename and last name or maximum 2 white space and atleast 1 white space */
   do {
   	 b = strlen(person.name);
       c = 0;
    for (a = 0;a<b;a++){
    	if (person.name[a] == ' '){
    		c++;

		}

		}

		if (c > 2 || c ==0){
			system("cls");
			printf("\n\n\n You are requeted to enter first and last name or first middle or last name. ");
			printf("\n\n Re - Enter your Name \t :");
			gets(person.name);

		} else {
			check_1 = 1;
		}

} while (check_1 == 0);

/* article 1.1.2 Correcting the upper and lower case of name */
person.name[0] = toupper(person.name[0]);
  for (a = 1;a<b;a++){
  	if (person.name[a-1] == ' '){
  		person.name[a] = toupper(person.name[a]);
	  }else {
	  	person.name[a] = tolower(person.name[a]);
	  }
  }

 /*sub group: 1.2 validation of age */
  /*Article :1.2.1 Age should be between 0 to 110 */

do{

	if (person.age > 0 && person.age<110){
	check_2 = 1;
	}
	else {
		system("cls");
			printf("\n\n\n You are requested to enter your age between 0 to 110. ");
			printf("\n\n Re - enter your Age \t :");
			scanf("%d",&person.age);
	}
}while(check_2 == 0);

/*sub group: 1.3 validation of email */
  /*Article :1.3.1 email should contain basic charecter like '@' and '.' */

  do {
  	emcheck1 =0;
  	emcheck2 =0;
  	emlen = strlen(person.email);
  	for (a = 0;a<emlen;a++){
  		if (person.email[a] == '@'){
  			emcheck1++;
		  }
		  if (person.email[a] == '.'){
  			emcheck2++;
		  }
	  }
	  if(emcheck1 == 1 && emcheck2 == 1){
	  	check_3 = 1;
	  	}
	  	else {
	  		system("cls");
			printf("\n\n\n You are requested to enter your Email correctly.");
			printf("\n\n Re - enter your Email \t :");
			gets(person.email);
		  }

  }while(check_3 == 0);
}

/*This section is designed to print ques and take and check ans*/


void solution_calculation(char *ques[],char*ans[],char right[],char *description[]){
	int a,d;
	int lifescr;
	static int curr;
	int money[15] = {100,200,300,500,1000,2000,4000,8000,16000,32000,64000,125000,250000,500000,1000000};
	static int trial1,trial2,trial3;
	 char input_ans;
	 srand(time(NULL));

	 a = rand() % 5;
	 d = a*4;
	 Rajat:
	 printf("\n Your question is: \n ");
	 puts(ques[a]);
	 printf("\n");
	 printf("\tA: %s \tB: %s \n\tC: %s \tD: %s",ans[d+0],ans[d+1],ans[d+2],ans[d+3]);
	 printf("\n\n\n\n\n For life line \n*Type X for 2X\n*Type Y for 50-50\n*Type Z for flip the question");
	 printf("\n\n\n\n\n\n Enter your answer: ");
	 fflush(stdin);
	 scanf("%c",&input_ans);
	/* if((toupper(input_ans)!='X'&&'Y'&&'Z'))
     {
       //  PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\lock.wav",NULL, SND_SYNC);
     } */



	 if (toupper(input_ans) == right[a] )
	 {
	 	printf("Correct Answer");
	 	printf("\n\n\n");
	 	puts(description[a]);
	 	person.score=money[curr];
       // PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\Correct ans.wav",NULL, SND_SYNC);

	 	printf("\n\n\t\t\t\t\tYOU EARNED $%d.",person.score);

	 }

	 else if ((toupper(input_ans) == 'X')&&(trial1==0))
	 {
	 	
	 	lifescr = money[curr];
	 	lifeline1(ques,ans,right,description,a,lifescr);
	 	trial1++;
	 	
	 }
	 else if ((toupper(input_ans) == 'X')&&(trial1!=0))
     {
     	 system("cls"); 
         printf(">>>>>>>YOUR 2X LIFELINE HAD ALREADY BEEN USED.<<<<<<<");
         goto Rajat;
     }


	 else if ((toupper(input_ans) == 'Y')&&(trial2==0))
	 {
	 	lifescr = money[curr];
	 	lifeline2(ques,ans,right,description,a,lifescr);
	 	trial2++;
	 	
	 }
	 else if ((toupper(input_ans) == 'Y')&&(trial2!=0))
     {  system("cls"); 
         printf(">>>>>>>YOUR 50-50 LIFELINE HAD ALREADY BEEN USED.<<<<<<<");

         goto Rajat;
     }
	 else if ((toupper(input_ans) == 'Z')&&(trial3==0))
	 {
	 	lifescr = money[curr];
	 	lifeline3(ques,ans,right,description,a,lifescr);
	 	trial3++;
	 	
	 }
	 else if ((toupper(input_ans) == 'Z')&&(trial3!=0))
     {   system("cls"); 
         printf(">>>>>>>YOUR Flip Question LIFELINE HAD ALREADY BEEN USED.<<<<<<<");
         goto Rajat;
     }
	 else {
	 	printf("Wrong Answer");
	 	printf("\n\n\n");
	 	puts(description[a]);
	 	//PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\wrong.wav",NULL, SND_SYNC);
	 	printf("\n\n\t\t\t\t\tYOU EARNED $%d.\n\nGAME OVER.", person.score);
	 	getch();
	 	score();

	 }
	 curr++;


}


/* lifeline 1 is for 2X */
void lifeline1(char *ques[],char*ans[],char right[],char *description[],int a,int lifescr)
{

    system("cls");


     printf ("/* Your 2X life line has been activated.\n");
	 int d;
	 char input_ans;

	 d = a*4;
	 printf("\n Your question is: \n ");
	 puts(ques[a]);
      printf("\tA: %s \tB: %s \n\tC: %s \tD: %s",ans[d+0],ans[d+1],ans[d+2],ans[d+3]);
     printf("\n\n Enter your answer: ");
     fflush(stdin);
	 scanf("%c",&input_ans);
	 //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\lock.wav",NULL, SND_SYNC);
	  if (toupper(input_ans) == right[a] )
	 {
	 	person.score=lifescr;
	 	printf("Correct Answer");
	 	printf("\n\n\n");
	 	puts(description[a]);
	 //	PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\Correct ans.wav",NULL, SND_SYNC);
        printf("\n\n\t\t\t\t\tYOU EARNED $%d.",person.score);


	 }else {
	 	printf("Wrong Answer.Please Try Again.");
	 	//PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\wrong.wav",NULL, SND_SYNC);
	 	printf("\n\n Enter your next answer: ");
	 fflush(stdin);
	 scanf("%c",&input_ans);
	 //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\lock.wav",NULL, SND_SYNC);

	  /* 2nd answer checking */
	  if (toupper(input_ans) == right[a] )
	 {
	 	person.score=lifescr; 
	 	printf("Correct Answer");
	 	printf("\n\n\n");
	 	puts(description[a]);
	 	
	 //	PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\Correct ans.wav",NULL, SND_SYNC);
	    printf("\n\n\t\t\t\t\tYOU EARNED $%d.",person.score);

	 }else {
	 	printf("\n Wrong Answer");
	 	printf("\n\n\n");
	 	puts(description[a]);
        //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\wrong.wav",NULL, SND_SYNC);
	 	printf("\n\n\t\t\t\t\tYOU EARNED $%d.\n\nGAME OVER.", person.score);
	 	getch();
		 score();
	 	
    }

	 }

     }



/* lifeline 2 is for 50 - 50 */
void lifeline2(char *ques[],char*ans[],char right[],char *description[],int a,int lifescr){

	system("cls");
    printf ("/* Your 50 - 50 life line has been activated.\n");

	 int b,c,d,i,j =0,p;
	 char corr;
	 corr = right[a];
	 switch(corr){
	 	case 'A':
	 		p = 0;
			break;
			case 'B':
	 		p = 1;
			break;
			case 'C':
	 		p = 2;
			break;case 'D':
	 		p = 3;
			break;

	 }
	 char input_ans;
	 d = a*4;
	 for (i = 0;j!=2;i++)
	 {
	 	b = rand();
	 	c = b%4;

	 	if (c != p && ans[d+c] != " "){
	 		j++;
	 		ans[d+c]=" ";


		 }

		 }


	 printf("\n Your question is: \n ");
	 puts(ques[a]);

     printf("\tA: %s \tB: %s \n\tC: %s \tD: %s",ans[d+0],ans[d+1],ans[d+2],ans[d+3]);
     printf("\n\n Enter your answer: ");
     fflush(stdin);
	 scanf("%c",&input_ans);
	 //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\lock.wav",NULL, SND_SYNC);
	if (toupper(input_ans) == right[a] )
	 {
	 	person.score=lifescr;
	 	printf("Correct answer");
	 	printf("\n\n\n");
	 	puts(description[a]);
	 //	PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\Correct ans.wav",NULL, SND_SYNC);
	  	printf("\n\n\t\t\t\t\tYOU EARNED $%d.",person.score);
	 }
	  else {
	 	printf("Wrong answer");
	 	printf("\n\n\n");
	 	puts(description[a]);
	 	//PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\wrong.wav",NULL, SND_SYNC);
	 	printf("\n\n\t\t\t\t\tYOU EARNED $%d.\n\nGAME OVER.", person.score);
	    getch();
	 	score();
	 }

}


/* lifeline 3 is for flip question */
void lifeline3(char *ques[],char*ans[],char right[],char *description[],int a,int lifescr){
	system("cls");
        printf ("/* Your flip question life line has been activated.\n");
	 int b,d,i;
	 char input_ans;
	 b = rand() % 5;
	 do{
	 b = rand() % 5;
	 }while(a == b);


	 d = b*4;

	 printf("\n Your question is: \n ");
	 puts(ques[b]);
	 printf("\n");
	 printf("\tA: %s \tB: %s \n\tC: %s \tD: %s",ans[d+0],ans[d+1],ans[d+2],ans[d+3]);

	 printf("\n\n\n\n\n\n Enter your Answer: ");
	 fflush(stdin);
	 scanf("%c",&input_ans);
	 //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\lock.wav",NULL, SND_SYNC);
	 if (toupper(input_ans) == right[b] )
	 {
	 	person.score=lifescr;
	 	printf("Correct answer");
	 	printf("\n\n\n");
	 	puts(description[b]);
	 	//PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\Correct ans.wav",NULL, SND_SYNC);
	 	printf("\n\n\t\t\t\t\tYOU EARNED $%d.",person.score);
	 }
	  else {
	 	printf("Wrong answer");
	 	printf("\n\n\n");
	 	puts(description[b]);
	 //	PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\wrong.wav",NULL, SND_SYNC);
	 	printf("\n\n\t\t\t\t\tYOU EARNED $%d.\n\nGAME OVER.", person.score);
	 	getch(); 
		score();
	 }



}

 /* guide line
 donot change any variavle name
 only change function name as void ques1 , void ques2, void ques3 according to ur level
 put all question, option, right, description on order
 check multiple time and report if any problem occur
 */

void ques1()
 {
    char *ques[6] = {"1.Complete this common saying: A stitch in time,_____________.","1.If the cost of one apple is $3 and one orange is $2,how much will five oranges and six apples cost?","1.Which of the following countries lie in Asia?","1. Which is the largest country of the world?","1. Which city was the epicenter of Corona virus?"};
    char *ans[21] = {"Reduces pain","Saves nine","Heals wounds","Prevents risk of infection","$32","$30","$28","$26","Mexico","Libya","Serbia","Nepal","Russia","Canada","Australia","China","Chengdu","Wuhan","Hangzhou","Xi'an"};
    char right[5] = {'B','C','D','A','B'};
    char *description[6] = {"A stitch in time,saves nine is a common saying that illustrates the importance of solving a problem before it gets big.",
                            "Six times three is eighteen and five times two is ten and when you add eighteen and ten you get twenty eight.",
                            "Mexico lies in North America, Libya in Africa and Serbia in France. Nepal lies in Asia and is popular for the highest peak in the world i.e Mt. Everest. It lies between India and China.",
                            "Russia is the largest country of the world with an area of 17.1 million sq.km. and lying in two continents (Asia and Europe). Canada is the second largest, China is the fourth largest and Australia is the sixth largest country",
                            "More than thirty-four thousand cases of corona virus have been detected so far with more than seven hundred deaths in China with most of the cases and deaths in Wuhan."};

    solution_calculation(ques,ans,right,description);

 }

  void ques2()
 {
    char *ques[6] = {"2. Who won the 2002 football World Cup?","2.Which planet is not named after a god?","2.What is the population of the Earth as of 2017?","2.Who was the president of America before Barack Obama?","2. Which band sang the popular song 'Bohemian Rhapsody'?"};
    char *ans[21] = {"Brazil","France","Italy","Germany","Mercury","Earth","Mars","Uranus","6.92 billion","7.53 billion","7.97 billion","8.63 billion ","Bill Clinton","Ronald Regan","George W. Bush","Jimmy Carter","Pink Floyd","Nirvana","Guns N Roses","Queen"};
    char right[5] = {'A','B','B','C','D'};
    char *description[6] = {"Brazil won the 2002 World Cup.The final was between Brazil and Germany which ended with a scoreline of 2-0 where Ronaldo scored both the goals for Brazil. ",
                            "Earth is the only planet not named after any god. Mercury is the Roman god of commerce, Mars is the Roman god of war and Uranus is the Roman god of Sky ",
                            "According to data from the World Bank, population of Earth peaked with a total of 7.53 billion people.",
                            "George W. Bush took the office in 2001 and worked until 2009 before Barack Obama took over the office. ",
                            "Bohemian Rhapsody was written by Queen's lead singer Freddie Mercury for their album A Night at the Opera. It is regarded as the best rock song of all time."};

    solution_calculation(ques,ans,right,description);

 }

 void ques3()
 {
    char *ques[6] = {"3. Who wrote the book 'War and Peace'?","3.Which is not a polytheistic religion?","3.Which of the following American presidents was not assassinated?","3. In which city does Romeo and Juliet take place?","3. Who directed the movie 'Titanic'?"};
    char *ans[21] = {"Charles Dickens","Jane Austen","Leo Tolstoy","Edgar Allan Poe","Taoism","Shinto","Shenism","Judaism","Richard Nixon","Abraham Lincoln","John F. Kennedy","James A. Garfield","Florence","Siena","Verona","Naples","Steven Spielberg","James Cameron","Martin Scorsese","Quentin Tarantino"};
    char right[5] = {'C','D','A','C','B'};
    char *description[6] = {"War and Peace was written by Leo Tolstoy and was published in 1869. It is regarded as one of his finest literary works.",
                            "Judaism is a monotheistic religion which is characterized by a belief in one transcendent God. Hebrew Bible is regarded as the main book of Judaism.",
                            "Abraham Lincoln, John F. Kennedy and James A. Garfield were all shot to death while Richard Nixon died of a stroke at the age of eighty-one. ",
                            "Romeo and Juliet took place in Verona and this is the reason it is called the 'City of Love'. The balcony in the story of Romeo and Juliet is a major touristic attraction in Verona.",
                            "Titanic was directed by James Cameron and is based on the sinking of RMS Titanic in 1912."};

    solution_calculation(ques,ans,right,description);

 }

 void ques4()
 {
    char *ques[6] = {"4. Who wrote the poem 'The Solitary Reaper?","4. Which book ends with 'So we beat on, boats against the current, borne back ceaselessly into the past'?","4.A group of crows is called _____?","4. How many humans have walked on the moon?","4. Who is called agent 007?"};
    char *ans[21] = {"William Wordsworth","Robert Frost","William Blake","Walt Whitman","To Kill A Mockingbird","Gone With The Wind","The Great Gatsby","Pride and Prejudice","A Flock","A Pack","A Parliament","A Murder","16","12","8","4","James Bond","John Wick","Han Solo","Indiana Jones"};
    char right[5] = {'A','C','D','B','A'};
    char *description[6] = {"William Wordsworth wrote 'The Solitary Reaper' in 1807.It's theme revolves around the power of human imagination to see the transcendent in the everyday.",
                            "This line is the closing line from the novel 'The Great Gatsby'. It is regarded as one of the finest closing lines in English Literature.",
                            "A Flock is a group of seagulls, A pack is a group of mules and A parliament is a group of owls. A group of crows is called a murder.",
                            "A total of twelve men have walked on the moon namely Neil Armstrong,Buzz Aldrin,Charles 'Pete' Conrad,Alan Bean,Alan Shepard,Ed Mitchell,David Scott,James Irwin,John Young,Charles Duke,Jack Schmitt and Gene Cernan",
                            "James Bond is very famously is regarded as agent 007 and it has become a common phrase worldwide to refer to James Bond."};

    solution_calculation(ques,ans,right,description);

 }

 void ques5()
 {
    char *ques[6] = {"5.Who is regarded as 'the Greatest English author'?","5. Who won the first Cricket World Cup?","5. How many pleats are there in a chef's have?","5. Which country was illuminati founded?","5. Laika,the first dog to go to space,belonged to which breed?"};
    char *ans[21] = {"Mark Twain","William Shakespeare","Charles Dickens","John Milton","Australia","England","West Indies","New Zealand","150","100","50","10","Germany","England","Serbia","USA","Doberman","Husky","Labrador","Mongrel"};
    char right[5] = {'D','C','B','A','D'};
    char *description[6] = {"John Milton is regarded as 'the Greatest English author' for his important works like 'Paradise Lost','Paradise Regained' and 'L'Allegro'. He was born in London, worked as a civil servant and dies at the age of sixty-five.",
                            "The first cricket World Cup was won by West Indies in 1975 in England. They played against Australia in the final and defeated them.",
                            "A proper chef's hat has a hundred pleats signifying hundred ways he knows to prepare an egg.",
                            "Illuminati was a secret society founded in Germany on 1 May 1776 by Adam Weishaupt.It's goals were to oppose superstition, obscurantism, religious influence over public life, and abuses of state power.",
                            "Laika was a mongrel.He was a stray dog who was launched to space in Soviet spacecraft Sputnik 2 on 3 November 1957."};

    solution_calculation(ques,ans,right,description);

 }


 void ques6()
 {
    char *ques[6] = {"6. Which is the only American state to begin with the letter 'P'?","6. Which country is Prague in?","6. What is the capital city of Spain?","6. Where is the world's most ancient forest found?","6. Which is the World's Largest Lake?"};
    char *ans[21] = {"Pennsylvania","Paderborn","Padova","Pantin","Serbia","Cambodia","Czech Republic","Philippines","Barcelona","Granada","Segovia","Madrid","Daintree Forest, Queensland, Australia","Crooked Forest, Poland","Monteverde Cloud Forest Reserve, Costa Rica","Sagano Bamboo Forest, Japan","Lake Superior","Caspian Sea","Lake Victoria","Lake Michigam"};
    char right[5] = {'A','C','D','A','B'};
    char *description[6] = {"All other options except Pennsylvania are cities of Different Countries.Paderborn is a city of Germany, Padova of Italy, and Pantin of France.",
                            "Prague is the capital and largest city in the Czech Republic, the 13th largest city in the European Union and the historical capital of Bohemia. Situated on the Vltava river, Prague is home to about 1.3 million people, while its metropolitan area is estimated to have a population of 2.6 million. The city has a temperate oceanic climate, with relatively warm summers and chilly winters.",
                            "All other options except Madrid are famous touristic places of Spain. And Madrid is also one of the most beautiful city in Spain. It’s nightlife is legendary, be careful lest you get swept away by the jolly crowd on the streets, all set to dance away the night. It is also known for its astounding museums, the Museo del Prado, Centro de Arte Reina Sofía and Museo Thyssen-Bornemisza being the crème. The essence of Madrid is cosmopolitan.",
                            "The Daintree Rainforest is a region on the northeast coast of Queensland, Australia, north of Mossman and Cairns. At around 1,200 square kilometres (460 sq mi),the Daintree is a part of the largest continuous area of tropical rainforest on the Australian continent. The Daintree Rainforest is a part of the Wet Tropics of Queensland Rainforest, that spans across the Cairns Region. The Wet Tropics Rainforest (that the Daintree is a part of) is the oldest continually surviving tropical rainforest in the world. Along the coastline north of the Daintree River, tropical forest grows right down to the edge of the sea.",
                            "Despite its name, Caspian Sea is often regarded as the world's largest lake with an area of 371,000 km^2 (143,000 sq mi), though it contains an oceanic basin (contiguous with the world ocean until 11 million years ago) rather than being entirely over continental crust."};

    solution_calculation(ques,ans,right,description);

 }
  void ques7()
  {
    char *ques[6] = {"7. Which sport is Constantino Rocca famous for?","7. Who is  the only heavyweight boxing champion to finish his career of 49 fights without ever having been defeated?","7. Which chess piece can only move diagonally?","7. In football, who was nicknamed 'The Divine Ponytail'?","7. Rehan Poncha is a well known sportsman in which one of the following sports?"};
    char *ans[21] = {"Golf","Basketball","Table Tennis","Hockey","Errol Spence Jr.","Terence Crawford","Terence Crawford","Chayaphon Moonsri","A Bishop","A Knight","A Pawn","A King","Roberto Baggio","Miroslav Klose","Francesco Acerbi","Mario Balotelli","Golf","Swimming","Billiards","Lawn Tennis"};
    char right[5] = {'A','C','A','A','B'};
    char *description[6] = {"Costantino Rocca (born 4 December 1956) is an Italian golfer. He was long known as the most successful male golfer that Italy has produced, until the 2018 success of Francesco Molinari, who credited Rocca as an inspiration to him following his Open victory. After a long career on the European Tour, Constantino is now playing on the European Seniors Tour. He has five European Tour wins and is best known for his second-place finish in the 1995 Open Championship, and his hole in one in 1995 Ryder Cup.",
                            "Rocco Francis Marchegiano was born into a working-class family in Brockton, Massachusetts, on September 1, 1923. After being drafted into the U.S. Army in 1943, he reportedly began boxing as a way to get out of kitchen duty and other less-than-desirable jobs. Marciano finished his military service in 1946 and continued to box as an amateur. He tried out for the Chicago Cubs, but his dream of becoming a pro baseball player ended when he was soon cut from the team. He returned to boxing and fought his first professional match on March 17, 1947, defeating Lee Epperson in a third-round knockout. Marciano went on to win his next 15 matches by knockout. He became known as a tough fighter and powerful puncher, but he was criticized for his awkward style, which some though lacked finesse.",
                            "A Knight moves in L-shape, A pawn moves either one or two steps on the same line, and a King can move in anydirection but only one step.",
                            "Roberto Baggio is an Italian former professional footballer who mainly played as a second striker, or as an attacking midfielder, although he was capable of playing in several offensive positions. He is the former president of the technical sector of the Italian Football Federation (FIGC). A technically gifted, creative playmaker and a set piece specialist, renowned for his curling free-kicks, dribbling skills, and goalscoring, Baggio is regarded as one of the greatest players of all time.",
                            "Rehan Jahangir Poncha is a six-time national champion Indian swimmer, Olympian and Arjuna Award winner, who specialized in backstroke, butterfly, and individual medley events. He is also the recipient of the Eklavya Award from the Karnataka Olympic Association. He is a 6-time Indian swimming champion, and a 6-time record holder in the butterfly (both 100 and 200 m). Poncha also set two of his records in the freestyle and medley relays at the 2009 Asian Swimming Championships in Foshan, China, along with his teammates Sandeep Sejwal, Virdhawal Khade, and Aaron D'Souza."};

    solution_calculation(ques,ans,right,description);

 }
 void ques8()
 {
    char *ques[6] = {"8. Which famous painter painted the picture 'The Last Supper'?","8. Which famous painter painted the picture 'Le Moulin de la Galette'?","8. Which famous painter painted the picture 'Sunflowers'?","8. Which famous painter painted the picture 'Creation of Adam – Sistine Chapel'?","8. Which famous painter painted the picture 'The Scream'?"};
    char *ans[21] = {"Leonardo Da Vinci","Vincent Van Gogh","Jan Vermeer","Jean Renoir","Leonardo Da Vinci","Vincent Van Gogh","Jan Vermeer","Jean Renoir","Leonardo Da Vinci","Vincent Van Gogh","Jan Vermeer","Jean Renoir","Michelangelo","Vincent Van Gogh","Jan Vermeer","Jean Renoir","Edvard Munch","Vincent Van Gogh","Jan Vermeer","Jean Renoir"};
    char right[5] = {'A','D','B','A','A'};
    char *description[6] = {"Leonardo da Vinci painted one of the most famous scenes in the Bible – The Last Supper. It is after Christ has said one of the disciples will betray him. This is the ultimate soap opera – the ultimate test of man – who will we serve, God or Mammon?",
                            "Bal du moulin de la Galette (commonly known as Dance at Le moulin de la Galette) is an 1876 painting by French artist Pierre-Auguste Renoir. It is housed at the Musée d'Orsay in Paris and is one of Impressionism's most celebrated masterpieces. The painting depicts a typical Sunday afternoon at the original Moulin de la Galette in the district of Montmartre in Paris. In the late 19th century, working class Parisians would dress up and spend time there dancing, drinking, and eating galettes into the evening.",
                            "Van Gogh’s paintings of Sunflowers are among his most famous. He did them in Arles, in the south of France, in 1888 and 1889. Vincent painted a total of five large canvases with sunflowers in a vase, with three shades of yellow ‘and nothing else’. In this way, he demonstrated that it was possible to create an image with numerous variations of a single colour, without any loss of eloquence. The sunflower paintings had a special significance for Van Gogh: they communicated ‘gratitude’, he wrote.",
                            "Michelangelo took four years to paint the Sistine Chapel. He chose scenes from the Old Testament. This is the moment of God creating Adam. This particular panel is just a fraction of the Sistine Chapel. To fully appreciate the scale, splendour and beauty of Michelangelo’s creation, you have to visit the Vatican.",
                            "This painting that symbolises the anguish and pain of modern life. It has become one of the most famous pictures of modern times. Somehow it makes us think of Freud and looking at our subconscious. It is famous, but is it good? Why look at the mud in the lily pond, when you can enjoy the lilies on top?"};

    solution_calculation(ques,ans,right,description);

 }
 void ques9()
 {
    char *ques[6] = {"9. Who among the following persons is called 'Desert Fox'?","9. Who is known as 'Little Corporal'?","9. Who was the first person to cross the Alps with army?","9. \"Senses are the gateways of knowledge\" was emphasised by?","9. Who said \" You give me blood, I will give you freedom\"?"};
    char *ans[21] = {"Walter Scott","Erwin Rommel","Eisenhower","Bismarck","Adolf Hitler","Napolean Bonaparte","William E. Gladstone","Queen Elizabeth","Hannibal","Napolean","Alexander","None of these","Gurunanak","Rousseau","Confucius","Mahaveera","Mahatma Gandhi","Bal Gangadhar Tilak","Subhash Chandra Bose","Bhagat singh"};
    char right[5] = {'B','B','A','B','C'};
    char *description[6] = {"Rommel was born in 1891 in Wurttenberg, Germany, the son of a teacher. During World War I, he showed himself to be a natural leader with unnatural courage, fighting in France, Romania, and Italy. At the outbreak of World War II, Rommel was given command of the troops that guarded Hitler’s headquarters, a disappointment for a man used to fighting on the front lines with the infantry. The nick name 'Desert Fox' was given to him beacuse of his tactics and surprise attacks.",
                            "Napoléon Bonaparte(15 August 1769 – 5 May 1821) was a French statesman and military leader who rose to prominence during the French Revolution and led several successful campaigns during the French Revolutionary Wars. He was Emperor of the French as Napoleon I from 1804 until 1814 and again briefly in 1815 during the Hundred Days. He was called Little Corporal due to his success in the series of battles in Italy. It was given to him, not because of his size, but because of his ranking, as he was a young and unknown corporal, which is why he was named that by his soldiers in 1796.",
                            "Hannibal(247 – between 183 and 181 BC) was a Carthaginian general and statesman who is widely considered one of the greatest military commanders in history. His father, Hamilcar Barca, was a leading Carthaginian commander during the First Punic War (264–241 BC). His younger brothers were Mago and Hasdrubal, and he was brother-in-law to Hasdrubal the Fair; all also commanded Carthaginian armies.",
                            "The Five senses that we have are: Sight, smell, hear, touch and taste. Rousseau emphasised that \"Senses are the gateways of knowledge\".",
                            "Subhas Chandra Bose (23 January 1897 – 18 August 1945) was an Indian nationalist whose defiant patriotism made him a hero in India, but whose attempt during World War II to rid India of British rule with the help of Nazi Germany and Imperial Japan left a troubled legacy. The honorific Netaji (Hindustani: \"Respected Leader\"), first applied in early 1942 to Bose in Germany by the Indian soldiers of the Indische Legion and by the German and Indian officials in the Special Bureau for India in Berlin, was later used throughout India."};

    solution_calculation(ques,ans,right,description);

 }
 void ques10()
 {
    char *ques[6] = {"10. Who was the first Chairman of the SAARC?","10. The first Asian Secretary general of U.N.O was?","10. Where is the Headquarter of ASEAN (Association of Southeast Asian Nations)?","10. How many member countries did the UNO have on its formation in 1945?","10. Which of the following is the only member of the G-15 from the Indian subcontinent?"};
    char *ans[21] = {"Mr. Zia ur Rehman","Lt.Gen H.M.Ershad","King Birendra","Mrs.Indira Gandhi","Vijaya Laxmi pandit","U.Thant","Trygve Lie","Kurt Waldheum","Jakarta","Beijing","Newyork","Da Nang","45","51","48","54","Nepal","Bangladesh","Burma","Pakistan"};
    char right[5] = {'B','C','A','B','D'};
    char *description[6] = {"Hussain Muhammad Ershad(1 February 1930 – 14 July 2019) was a Bangladeshi Army Chief and politician who served as the President of Bangladesh from 1983 to 1990, a time many consider to have been a military dictatorship. He seized power as head of the army during a bloodless coup against President Abdus Sattar on 24 March 1982 (by imposing martial law and suspending the Constitution). He declared himself President in 1983, and subsequently won the controversial 1986 Bangladeshi presidential election. Despite claims to have legitimately won the 1986 election, many consider his regime as an era of military dictatorship.",
                            "Trygve Halvdan Lie(16 July 1896 – 30 December 1968) was a Norwegian politician, labour leader, government official and author. He served as Norwegian foreign minister during the critical years of the Norwegian government in exile in London from 1940 to 1945. From 1946 to 1952 he was the first Secretary-General of the United Nations. Lie earned a reputation as a pragmatic, determined politician.",
                            "The ASEAN Headquarters is located in Jakarta, Indonesia. ASEAN(The Association of Southeast Asian Nations) is a group of ten Southeast Asian countries. It was formed on 8th August 1967. The 10 countries in ASEAN are Indonesia, Malaysia, Philippines, Singapore, Brunei, Myanmar, Cambodia, Laos, Vietnam and Thailand. Its main purpose include the acceleration of economic growth, social progress, cultural development among its members, the protection of the peace and stability of the region, and to provide opportunities for member countries to discuss differences peacefully.",
                            "The original members of the United Nations were: the Republic of China, France, the Soviet Union, the United Kingdom, the United States (these first five forming the Security Council), Argentina, Australia, Belgium, Bolivia, Brazil, Byelorussia, Canada, Chile, Colombia, Costa Rica, Cuba, Czechoslovakia, Denmark, the Dominican Republic, Ecuador, Egypt, El Salvador, Ethiopia, Greece, Guatemala, Haiti, Honduras, India, Iran, Iraq, Lebanon, Liberia, Luxembourg, Mexico, the Netherlands, New Zealand, Nicaragua, Norway, Panama, Paraguay, Peru, the Philippines, Poland, Saudi Arabia, South Africa, Syria, Turkey, Ukraine, Uruguay, Venezuela and Yugoslavia.",
                            "The Group of 15 (G-15) is an informal forum set up to foster cooperation and provide input for other international groups, such as the World Trade Organization (WTO) and the Group of Seven. It was established at the Ninth Non-Aligned Movement Summit Meeting in Belgrade, Yugoslavia, in September 1989, and is composed of countries from Latin America, Africa, and Asia with a common goal of enhanced growth and prosperity. The G-15 focuses on cooperation among developing countries in the areas of investment, trade, and technology. Membership has since expanded to 18 countries, but the name has remained unchanged."};

    solution_calculation(ques,ans,right,description);

 }

  void ques11(){
	char *ques[6] = {"11. How many academy awards does Al Pacino have? ","11. Which batsman has reached the second highest Test average in cricket?","11. Who won the best actor award in 2016 Academy Awards?","11. Which of the following is a Tom Hanks movie?","11. According to United Nations, how many countries are there in Africa?"};
    char *ans[21] = {"Zero","One","Two","Three","Sachin Tendulkar","Virat Kohli","Ricky Ponting","Steven Smith","Eddie Redmayne","Johnny Depp","Leonardo DiCaprio","Brad Pitt","Splash","Jaws","Aviator","Citizen Kane","38","46","54","62"};
    char right[5] = {'B','D','C','A','C'};
    char *description[6] = {"Al Pacino has won one academy award for his performance in 'Scent of a Woman'. He has a total of nine nominations for movies like 'The Godfather','The Godfather II','Dog Day Afternoon' etc.",
                            "Steven Smith of Australia has held the second highest average ever of 64.95. The highest average belongs to Sir Donald Bradman of Australia which was staggering 99.94. ",
                            "Leonardo DiCaprio won the best actor award in 2016 Academy Awards for his performance in 'The Revenant'.It was his first oscar in seven nominations for movies like 'The Wolf of Wallstreet','Blood Diamond','The Aviator' etc.",
                            "Tom Hanks starred in the movie Splash. In this movie he plays the role of a young man who falls in love with a mysterious woman who is secretly a mermaid.",
                            "According to United Nations, there are 54 countries in Africa.Aside from 54 recognized states, there are two states whose independence is disputed (Western Sahara and Somaliland)"};

    solution_calculation(ques,ans,right,description);

 }

 void ques12(){
    char *ques[6] = {"12. How many teeth do elephants have?","12. Which country has a city named 'Split'? ","12. Which of the following physicists  is not a Nobel Prize winner?","12. Which of the following dinosaurs was the smallest in size? ","12. Who will be the first human to set foot on Mars?"};
    char *ans[21] = {"2","14","26","34","Iceland","Austria","England","Croatia","Richard Feynman","Wolfgang Pauli","James Clerk Maxwell","Luis Walter Alvarez","Compsognathus","Trodor","Microraptor","Ornithomimus","Michael Collins","Alyssa Carson","Lisa Cuddy","Remy Hadley"};
    char right[5] = {'C','D','C','A','B'};
    char *description[6] = {"Elephants usually have 26 teeth: 2 incisors, known as the tusks, 12 deciduous premolars, and 12 molars.",
                            "Split lies in Croatia. It is the second largest city of Croatia with about 250,000 people living in its urban area. It is the largest city of the region of Dalmatia.",
                            "Richard Feynman received his nobel prize in 1965 for his fundamental work in quantum electrodynamics(QED).Luis Walter Alvarez won his nobel prize in 1968 for is decisive contributions to elementary particle physics. Wolfgang Pauli won his nobel prize in 1945 for the discovery of the Exclusion Principle. Maxwell didn't receive a nobel prize because he died 1879 but nobel prize was started to be given later from 1901.",
                            "Compsognathus was the smallest dinosaur to ever exist. They bipedal, carnivorous theropod dinosaur.Compsognathus could grow to around the size of a turkey.",
                            "Alyssa Carson will be the first person to land on Mars. She is from Hammond, Louisiana, United States and is the youngest person to graduate from the Project PoSSUM (Project Polar Suborbital Science in the Upper Mesosphere) academy, a specialised training programme for astronauts.She's 18 years old and plans to go to mars in about ten years under Elon Musk's Mars Transportation Program which is planned to take place by 2024."};

    solution_calculation(ques,ans,right,description);
 }

 void ques13(){
	char *ques[6] = {"13. Which satellite is farthest from the Earth?","13. What was the name of telescope that captured the first photo of Blackhole?","13. Where did Rugby originate?","13. Papua New Guinea lies in which continent?","13. Who hosted the first television talk show?"};
    char *ans[21] = {"Skylab","Pioneer 11","Mariner 4","Voyager 1","James Webb Space Telescope","Event Horizon Telescope","Spritzer Space Telescope","Lisa Pathfinder","USA","Argentina","England","France","Asia","Africa","South America","Australia and Oceania","Joe Franklin","Johnny Carson","Phil Donahue","David Letterman"};
    char right[5] = {'D','B','C','D','A'};
    char *description[6] = {"Voyager 1 is farthest from earth and has left our solar system.It is moving at a speed of 38,000 mph (61,000 km/h) and is currently 11.7 billion miles (18.8 billion kilometers) from Earth.",
                            "Event Horizon Telescope took the first picture of black hole.It is a global network of synchronized radio observatories that work in unison to observe radio sources associated with black holes with angular resolution comparable to their event horizons.It took the picture of a black hole in the galaxy Messier 87.",
                            "Rugby originated in England at Rugby School in Warwickshire in 1823 when during a game of football, William Webb Ellis decided to pick up a ball and go with it.",
                            "Papua New Guinea lies in Australia and Oceania. It is a country in Oceania that occupies the eastern half of the island of New Guinea and its offshore islands in Melanesia, a region of the southwestern Pacific Ocean north of Australia. Its capital, located along its southeastern coast, is Port Moresby.",
                            "Joe Franklin hosted the first ever talk show.The show began in 1951 on WJZ-TV (later WABC-TV) and moved to WOR-TV (later WWOR-TV) from 1962 to 1993."};

    solution_calculation(ques,ans,right,description);

 }

void ques14(){
	char *ques[6] = {"14. Which is the smallest bird after The Bee Hummingbird?","14. Which of the following rovers is not currently present in Mars?","14. What was the name of the first aeroplane?","14. Which of the following is a moon of Jupiter?","14. What is the name of first and only photographed blackhole?"};
    char *ans[21] = {"The Weebil","The Pardalote","The Goldcrest","The Bannaquit","Sojourner","Anaxagoras","Spirit","Opportunity","Wright Flyer","Wright 03-01","Bleriot 1","Cessna","Tethys","Oberon","Rhea","Adrastea","Abell","Cygnus","Powehi","Sombrero"};
    char right[5] = {'A','B','A','D','C'};
    char *description[6] = {"The weebil is the second smallest bird.It is a species of bird in the family Acanthizidae, it is an insectivorous passerine that is found throughout mainland Australia. At 8 to 9 cm (3.1 to 3.5 in) long, it is Australia's smallest bird",
                            "The rovers Sojourner, Spirit and Opportunity were all sent to mars in 1996,2003 and 2003 respectively while Anaxagoras was sent to moon.",
                            "The first aeroplane was Wright flyer. It first flew on December 17, 1903 and was made by Wilbur and Orville Wright, commonly known as the Wright Brothers.",
                            "Tethys is the moon of Saturn and Oberon and Rhea are the moons of Uranus. So Adrastea is the moon of Jupiter.",
                            "The first and only photographed black hole that lies in the galaxy Messier 87 was named Powehi."};

    solution_calculation(ques,ans,right,description);


 }

 void ques15(){
    char *ques[6] = {"15. What was the name of first aeroplane that broke the sound barrier?","15. Who wrote the book 'The Moral Landscape'?","15. Which dinosaur had the longest neck?","15. Which is a black hole?","15. What was the name of first British satellite to be placed in orbit?"};
    char *ans[21] = {"Cirris SR22","Learjet 23","Lockheed C-130","Bell X-1","Sam Harris","Daniel Dennett","Christopher Hitchens","Peter Atkins","Brachiosaurus","Memenchisaurus","Apatosaurus","Diplodocus","NGC1068","M81","HLX-1","GN-z11","Sputnik","Prospero","Miranda","Ariel"};
    char right[5] = {'D','A','B','C','D'};
    char *description[6] = {"Bell X-1 was the first aeroplane to break the sound barrier.It was a rocket engine–powered aircraft built by Bell Aircraft in 1945.",
                            "Sam Harris wrote the book 'The Moral Landscape'. It's theme revolves around how science and not religion can answer the moral questions of humanity and determine human values.It was published on October 5, 2010",
                            "Memenchisaurus had the longest necks.Their necks were around thirty feet long.They were herbivores and ate a tremendous amount of plant each day to sudtain itself.",
                            "HLX-1 is a blackhole which is located in the galaxy ESO 243-49 about 290 million light-years from Earth.NGC1068 or Messier 77 is a barred spiral galaxy about 47 million light-years away in the constellation Cetus.GN-z11 is a high-redshift galaxy found in the constellation Ursa Major and is the oldest and most distant known galaxy in the observable universe.M81 is the remotest galaxy observable with the naked-eye and is 12 million light-years away. ",
                            "Laika was a mongrel.He was a stray dog who was launched to space in Soviet spacecraft Sputnik 2 on 3 November 1957."};

    solution_calculation(ques,ans,right,description);

 }

 int main ()
 {
 	
 	 

    printf("\t\t\t\t\tWELCOME TO THE GAME 'WHO WANTS TO BE A MILLIONAIRE?'\n");
    printf("Created by: \nRajat Dulal\nBishwambhar Dahal\nSuramya Pokhrel ");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\Welcome.wav",NULL, SND_SYNC);
    printf("\n\n\n>>>>>>>>>>GAME INSTRUCTIONS<<<<<<<<<<\n");
    printf("\n1. 'Who wants to be a Millionaire?' is a quiz game in which a player has to answer 15 questions correctly(one after another) to be a millionaire.\n2. After Entering the answer the player cannot change his/her answer.\n3. To each question the player gets 4 options among which he/she should choose the correct answer.\n4. To answer the question, the players is only allowed to type either 'A' for first option, 'B' for second option, 'C for third option and 'D' for fourth option.\n");
    printf("5. For the aid of player in answering the questions, there are three lifelines available in the game- 50-50, Flip the question and Double Dip.\n6. Player can use each lifeline only one time in a game.\n7. The alphabets are Case-Insensitive.\n8. Player is not allowed to use 2 lifelines in the same question.\n\n\nWARNING: DONOT ENTER ANY OTHER ALPHABETS WHILE ANSWERING THE GAME UNLESS YOU WANT YOUR GAME TO QUIT.\n\n");
    person_info();
    system("cls");
    printf("\t\t\t\t\t\tPlayer's Info:");
	printf("\n\n\t\t\t\t\tName: %s",person.name);
	printf("\n\n\t\t\t\t\tAge: %d",person.age);
	printf("\n\n\t\t\t\t\tEmail:%s\n ",person.email);
	//PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\intro.wav",NULL, SND_SYNC);
	system("cls");
	printf("Press any Key to Continue.");
	getch();
	system("cls");
	
	//PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\1.wav",NULL, SND_SYNC);
	//PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
	time_t starttime; 
    starttime = time(NULL);
    initialtime = starttime;
	ques1();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\2.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques2();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\3.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques3();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\4.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques4();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\5.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques5();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\6.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques6();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\7.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques7();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\8.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques8();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\9.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques9();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\10.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques10();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\11.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques11();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\12.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques12();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\13.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques13();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\14.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques14();
    getch();
    system("cls");
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\15.wav",NULL, SND_SYNC);
    //PlaySound("C:\\Users\\Lenovo\\Desktop\\Project C\\question.wav",NULL, SND_SYNC);
    ques15();
    getch();
    system("cls");

    return 0;

 }


