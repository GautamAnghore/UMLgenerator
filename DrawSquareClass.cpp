#include <ncurses.h>

class square
{
	int sy,sx;
	int height,width;
	char ch;
	int colorPair;
	bool border_status;
	WINDOW * win;

public:
	square(int colorPair,bool border_status=FALSE,WINDOW * win = stdscr)
	{
		this->win=win;
		this->colorPair=colorPair;
		this->border_status=border_status;
		getmaxyx(win,height,width);
		sy=0;sx=0;
		ch=' ';
	}
	square(int sy,int sx,int height,int width,char ch,int colorPair,bool border_status=FALSE,WINDOW * win = stdscr)
	{
		this->sy=sy;
		this->sx=sx;
		this->height=height;
		this->width=width;
		this->ch=ch;
		this->colorPair=colorPair;
		this->border_status=border_status;
		this->win=win;
	}
	void update(int sy,int sx,int height,int width,char ch,int colorPair,bool border_status=FALSE,WINDOW * win = stdscr)
	{
		this->sy=sy;
		this->sx=sx;
		this->height=height;
		this->width=width;
		this->ch=ch;
		this->colorPair=colorPair;
		this->border_status=border_status;
		this->win=win;
	}

	void setyx(int y,int x)
	{
		sy=y;
		sx=x;
	}
	void sethw(int height,int width)
	{
		this->height=height;
		this->width=width;
	}
	void setcolor(int colorPair)
	{
		this->colorPair=colorPair;
	}
	void border_status_update(bool status)
	{
		border_status=status;
	}
	void draw();
};

void square::draw()
{
	wattron(win,COLOR_PAIR(colorPair));

	for(int i=sx;i<=width;i++)
		for(int j=sy;j<=height;j++)
			mvwaddch(win,j,i,ch);

	if(border_status)
	{
		mvwhline(win,sy,sx,ACS_HLINE,width);
		mvwhline(win,sy+height-1,sx,ACS_HLINE,width);
		mvwvline(win,sy,sx,ACS_VLINE,height);
		mvwvline(win,sy,sx+width-1,ACS_VLINE,height);

		mvwaddch(win,sy,sx,ACS_ULCORNER);
		mvwaddch(win,sy+height-1,sx,ACS_LLCORNER);
		mvwaddch(win,sy,sx+width-1,ACS_URCORNER);
		mvwaddch(win,sy+height-1,sx+width-1,ACS_LRCORNER);
	}
	wrefresh(win);

	wattroff(win,COLOR_PAIR(colorPair));
}


int main()
{

	initscr();
	raw();
	start_color();
	keypad(stdscr,TRUE);
	noecho();
	
	init_pair(1,COLOR_CYAN,COLOR_CYAN);

	// background base
	square base(1,FALSE);
	base.draw();
	getch();

	WINDOW *sq;
	sq=newwin(5,180,1,1);

	init_pair(2,COLOR_WHITE,COLOR_RED);

	square sq_base(2,TRUE,sq);
	sq_base.draw();

	wrefresh(sq);
	getch();
	delwin(sq);

	base.draw();

	getch();
	endwin();
}