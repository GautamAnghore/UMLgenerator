#include <ncurses.h>

void initialise()
{
	initscr();
	raw();
	start_color();
	keypad(stdscr,TRUE);
	noecho();
}

class line
{
	int ya,xa;
	int yb,xb;
	int colorPair;
	WINDOW * win;

	public :
	line(int ya,int xa,int yb,int xb,int colorPair,WINDOW * win = stdscr)
	{
		this-> ya=ya;
		this-> xa=xa;
		this-> yb=yb;
		this-> xb=xb;
		this-> colorPair=colorPair;
		this-> win=win;
	}

	void setyx(int ya,int xa,int yb,int xb)
	{
		this-> ya=ya;
		this-> xa=xa;
		this-> yb=yb;
		this-> xb=xb;		
	}

	void setcolor(int colorPair)
	{
		this-> colorPair=colorPair;
	}


	void draw();
};

void line::draw()
{
	wattron(win,COLOR_PAIR(colorPair));
	int x1,y1;
	int x2,y2;

	if(ya==yb)
	{
		if(xa<xb)
		{
			x1=xa;
			x2=xb;
		}
		else
		{
			x1=xb;
			x2=xa;
		}
		mvwhline(win,ya,x1,ACS_HLINE,x2-x1);	
	}
	else if(xa==xb)
	{
		if(ya<yb)
		{
			y1=ya;
			y2=yb;
		}
		else
		{
			y1=yb;
			y2=ya;
		}
		mvwvline(win,y1,xa,ACS_VLINE,y2-y1);
	}
	else
	{
		int width,height;

		if(ya<yb)
		{
			x1=xa;
			y1=ya;
			x2=xb;
			y2=yb;
		}
		else
		{
			x1=xb;
			y1=yb;
			x2=xa;
			y2=ya;
		}

		height=y2-y1;

		if(x1<x2)
		{
			width=x2-x1;

			mvwvline(win,y1,x1,ACS_VLINE,height/2);
			
			mvwhline(win,y1+height/2,x1,ACS_HLINE,width);
			
			mvwvline(win,y1+height/2,x2,ACS_VLINE,height/2);
			
			mvwaddch(win,y1+height/2,x1,ACS_LLCORNER);
			mvwaddch(win,y1+height/2,x2,ACS_URCORNER);
		}
		else
		{
			width=x1-x2;

			mvwvline(win,y1,x1,ACS_VLINE,height/2);
			
			mvwhline(win,y1+height/2,x2,ACS_HLINE,width);
			
			mvwvline(win,y1+height/2,x2,ACS_VLINE,height/2);

			mvwaddch(win,y1+height/2,x1,ACS_LRCORNER);
			mvwaddch(win,y1+height/2,x2,ACS_ULCORNER);
		}

	}


	wrefresh(win);

	attroff(COLOR_PAIR(colorPair));
}

int main()
{
	initialise();
//	line(int ya,int xa,int yb,int xb,int colorPair,WINDOW * win = stdscr)

	init_pair(1,COLOR_WHITE,COLOR_CYAN);

	line l1(2,2,10,2,1),l2(2,4,2,40,1);
	l1.draw();
	l2.draw();
	getch();

	l1.setyx(5,5,20,25);
	l2.setyx(15,10,3,120);

	l1.draw();
	l2.draw();

	l1.setyx(50,5,70,150);
	l2.setyx(70,10,3,180);

	l1.draw();
	l2.draw();

	getch();

	endwin();
}