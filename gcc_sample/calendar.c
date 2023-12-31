#include <stdio.h>
 
int day_of_week(int ,int ); //함수 선언
int print_calendar(int ,int ,int);
void print_head(int ,int );
int year; //년
int month;

int main(void)
{         
           //월
           int day; //해당월 1일의 요일
          
           do {
                     printf("년도와 월을 입력하시오(2009 8과 같은 형식으로)\n>> ");
         //            scanf("%d%d",&year,&month); //년월 입력
                     if(month>=1 && month<=12)
                                break;
                     else
                                printf("잘못된 입력입니다\n>> ");
           } while (1);
          
           day = day_of_week(year,month); //해당월 시작요일 구하기
          
           print_head(year,month); //달력 상단부 출력
          
           //달력 날짜 출력
          
           return print_calendar(day,year,month); }
/****************************/
int day_of_week(int year,int month) //총 일수를 구하는 함수(해당 월 1일이 무슨요일인지 알기위해)
{
           int temp = 0; //임시로 계산에 사용할 변수
           int i; //for 문에서 사용할 변수
          
           for(i=1;i<year;i++) { //년도별 일수
                     if((i%4 == 0) && (i%100 != 0) || (i%400 == 0)) {
                                temp += 366;
                     } else {
                                temp += 365;    
                     }
           }
          
           for(i=1;i<month;i++) { //매 달 일수
                     if ( i==2 ) { // 2월일경우 윤년 검사
                                if((year%4==0) && (year%100 != 0) || (year%400 == 0))
                                          temp += 29;
                                else
                                          temp += 28;
                     }
                     switch (i) {
                     case 1:
                     case 3:
                     case 5:
                     case 7:
                     case 8:
                     case 10:
                     case 12:
                                temp += 31; //한달이 31일인 경우
                                break;
                     case 4:
                     case 6:
                     case 9:
                     case 11:
                                temp += 30; //한달이 30일인 경우
                                break;
                     }
           }
          
           temp = temp + 1; //마지막으로 일수를 더해 총 일 수를 구한다
          
           return temp % 7; //1=월,2=화...6=토,0=일
}
/****************************/
int print_calendar(int sd, int year, int month) //달력을 출력하는 함수
{
           int i, j; //for문
           int temp; //해달 월의 총 일수
          
		   printf("%d,%d,%d\n",sd,year,month);
           switch (month) { //한달의 일수를 구한다
           case 1:       case 3:       case 5:       case 7:       case 8:       case 10:       case 12:
                     temp = 31; //한달이 31일인 경우
                     break;
           case 4:       case 6:       case 9:       case 11:
                     temp = 30; //한달이 30일인 경우
                     break;
           case 2: //2월의 경우
                     if((year%4==0) && (year%100 != 0) || (year%400 == 0))
                                temp = 29;
                     else
                                temp = 28;
		   default :
			   printf("%d is invalid month! \n",month);
			   return 1;
           }
           printf("start!\n\n");
           printf("\t      ");
           for(i=1;i<=sd;i++)
               printf("        ");

		   j = sd;
           for(i=1;i<=temp;i++) {
                     if(j == 7) { //요일별로 출력되도록 줄바꿈
                                printf("\n\t      ");
                                j = 0;
                     }
                     printf("%2d      ",i);
                     j++;
           }
           printf("\n\n");
		   return 0;

}
/****************************/
void print_head(int year,int month) //달력의 상단부 양식을 출력하는 함수
{
           printf("\n\t\t\t\t[%d년 %02d월]\n\n",year,month);
           printf("\t      일      월      화      수      목      금      토\n");
}
