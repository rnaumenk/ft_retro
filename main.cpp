#include "Map.hpp"
#include "Player.hpp"
#include "Bot1.hpp"
#include "Bullet.hpp"
#include "Bot2.hpp"
#include "Bot3.hpp"
#include "Star.hpp"

void	rs_check_window(void)
{
	if (COLS < 125 || LINES < 32)
	{
		attron(A_BOLD);
		attron(A_UNDERLINE);
		mvprintw(LINES / 2, COLS / 2, "YO YO YO YO");
		mvprintw(LINES / 2 + 1, COLS / 2, "Take relax!");
		if (COLS < 185 && LINES < 40)
			mvprintw(LINES / 2 + 2, COLS / 2,
					 "Make the window wider and higher!");
		else if (COLS < 185 && LINES >= 40)
			mvprintw(LINES / 2 + 2, COLS / 2,
					 "Make the window wider!");
		else if (COLS >= 185 && LINES < 40)
			mvprintw(LINES / 2 + 2, COLS / 2,
					 "Make the window higher!");
		getch();
		endwin();
		exit(0);
	}
}

void		rs_menu(Map *menu, Player *player, int i)
{
	attron(COLOR_PAIR(2));
	attron(A_BOLD);
	if (i == 0)
		mvprintw(2, 133, ">> PRESS ANY KEY <<", player->get_life());
	if (i == 1)
	{
		mvprintw(2, 133, "                              ");
		mvprintw(2, 133, ">> RUNNING <<", player->get_life());
		mvprintw(17, 125, "PRESS: > Q < to EXIT GAME");
	}
	mvprintw(5, 125, "LIFES: %d", player->get_life());
	mvprintw(7, 125, "PRESS > P < to PAUSE GAME");
	mvprintw(9, 125, "PRESS: arrow right to move right");
	mvprintw(11, 125, "PRESS: arrow left to move left");
	mvprintw(13, 125, "PRESS: arrow down to move down");
	mvprintw(15, 125, "PRESS: arrow up to move up");
	mvprintw(24, 128, "--->>  SCORE: %4d  <<---", menu->get_score());
	attroff( COLOR_PAIR(2));
	attroff(A_BOLD);
}

void		rs_control(Player *player, Bullet * bullet, int bullet_num)
{
	int		key = getch();
	int		i = bullet_num;

	attron(COLOR_PAIR(2));
	attron(A_BOLD);
	if (key == 260 || key == 261 || key == 259 || key == 258)
		mvprintw(player->get_y(), player->get_x(), " ");
	if (key == 260 && player->get_x() > 1)
		player->set_x(player->get_x() - 1);
	else if (key == 261 && player->get_x() < 117)
		player->set_x(player->get_x() + 1);
	else if (key == 259 && player->get_y() > 1)
		player->set_y(player->get_y() - 1);
	else if (key == 258 && player->get_y() < 28)
		player->set_y(player->get_y() + 1);
	else if (key == ' ')
	{
		while (--i >= 0)
		{
			if (bullet[i].getX() == -1 && bullet[i].getY() == -1)
			{
				bullet[i].setX(player->get_x() + 1);
				bullet[i].setY(player->get_y());
				break ;
			}
		}
	}
	else if (key == 'p') {
		mvprintw(2, 133, ">>  PAUSE  <<");
		while (1) {
			if (getch() == 'p') {
				mvprintw(2, 133, ">> RUNNING <<", player->get_life());
				break ;
			}
			else if (getch() == 'q') {
				endwin();
				exit (0);
			}
		}
	}
	else if (key == 'q') {
		endwin();
		exit (0);
	}
	attroff( COLOR_PAIR(2));
	attroff(A_BOLD);
}

int     createBot1(Bot1 * bot1, int bots1_num)
{
	int i = bots1_num;
				
	while (--i >= 0)
	{
		if (bot1[i].getY() == -1 && bot1[i].getX() == -1)
		{
			bot1[i].spawn();
			bots1_num--;
			break ;
		}
	}
	return (bots1_num);
}

int     createBot2(Bot2 * bot2, int bots2_num)
{
	int i = bots2_num;
				
	while (--i >= 0)
	{
		if (bot2[i].getY() == -1 && bot2[i].getX() == -1)
		{
			bot2[i].spawn();
			bots2_num--;
			break ;
		}
	}
	return (bots2_num);
}

int     createBot3(Bot3 * bot3, int bots3_num)
{
	int i = bots3_num;
				
	while (--i >= 0)
	{
		if (bot3[i].getY() == -1 && bot3[i].getX() == -1)
		{
			bot3[i].spawn();
			bots3_num--;
			break ;
		}
	}
	return (bots3_num);
}

int		main()
{
	Map		map;
	Map		menu;
	Player	player;
	int 	bots1_num = 30;
	int 	bots2_num = 15;
	int 	bots3_num = 5;
	int     bullet_num = 100;
	int     stars_num = 3304;
	Star    star[stars_num];
	Bot1    bot1[bots1_num];
	Bot2    bot2[bots2_num];
	Bot3    bot3[bots3_num];
	Bullet  bullet[bullet_num];

	
	int 	i = 0;
	int     j = 0;
	int     n = 0;
	int 	l = 0;
	int     t;
	int     k;

	map.init_map();
	rs_check_window();
	box(map.get_map(), 0, 0);
	wrefresh(map.get_map());
	rs_menu(&menu, &player, 0);
	getch();
	timeout(1);
	while (1) {
		int x = getmaxx(stdscr);
		int y = getmaxy(stdscr);
		if (y < 35 || x < 170) {
			endwin();
			system("clear");
			std::cout << "DONT TOUCH TERMINAL" << std::endl;
			exit (0);
		}
		if (player.get_life() == 0) {
			while (1) {
				t = -1;
				for (n = 1; n < 29; n++)
				{
					for (k = 1; k < 119; k++)
					{
						mvwprintw(map.get_map() ,n, k, (star[++t].getVisibility() == 1 ? "." : " "));
					}
				}
				attron(A_BOLD);
				mvwprintw(map.get_map(), 14, 59, "GAME OVER");
				mvwprintw(map.get_map(), 15, 54, "PRESS > Q < TO EXIT");
				wrefresh(map.get_map());
				if (getch() == 'q') {
					endwin();
					exit(0);
				}
			}
		}
		if ((bots1_num > 0 || bots2_num > 0 || bots3_num > 0) && j == 300)
		{
			if ((bots1_num = createBot1(bot1, bots1_num)) < 20 && l % 1000 == 0)
			{
				if ((bots2_num = createBot2(bot2, bots2_num)) < 10 && l % 1000 == 0)
					bots3_num = createBot3(bot3, bots3_num);
			}
			j = 0;
		}
		wattron(map.get_map(), COLOR_PAIR(5));
		for (n = 0; n < 30; n++)
		{
			if (bot1[n].getY() != -1)
				mvwprintw(map.get_map() ,bot1[n].getY(), bot1[n].getX(), " ");
		}
		for (n = 0; n < 15; n++)
		{
			if (bot2[n].getY() != -1)
				mvwprintw(map.get_map() ,bot2[n].getY(), bot2[n].getX(), " ");
		}
		for (n = 0; n < 5; n++)
		{
			if (bot3[n].getY() != -1)
				mvwprintw(map.get_map() ,bot3[n].getY(), bot3[n].getX(), " ");
		}
		wattroff(map.get_map(), COLOR_PAIR(5));
		for (n = 1; n < 29; n++)
		{
			for (k = 1; k < 119; k++)
			{
				mvwprintw(map.get_map() ,n, k, " ");
			}
		}
		for (n = 0; n < bullet_num; n++)
		{
			k = -1;
			while (bullet[n].getY() != -1 && ++k < 30)
			{
				if (bullet[n].getY() == bot1[k].getY() && (bullet[n].getX() == bot1[k].getX() || bullet[n].getX() == bot1[k].getX() - 1))
				{
					bullet[n].blow();
					menu.set_score(bot1[k].kill());
					break ;
				}
			}
			k = -1;
			while (bullet[n].getY() != -1 && ++k < 15)
			{
				if (bullet[n].getY() == bot2[k].getY() && (bullet[n].getX() == bot2[k].getX() || bullet[n].getX() == bot2[k].getX() - 1))
				{
					bullet[n].blow();
					menu.set_score(bot2[k].kill());
					break ;
				}
			}
			k = -1;
			while (bullet[n].getY() != -1 && ++k < 5)
			{
				if (bullet[n].getY() == bot3[k].getY() && (bullet[n].getX() == bot3[k].getX() || bullet[n].getX() == bot3[k].getX() - 1))
				{
					bullet[n].blow();
					menu.set_score(bot3[k].kill());
					break ;
				}
			}
		}
		for (n = 0; n < 30; n++)
		{
			if (bot1[n].getX() == player.get_x() && bot1[n].getY() == player.get_y())
			{
				player.set_life(player.get_life() - 1);
				bot1[n].kill(1);
			}
		}
		for (n = 0; n < 15; n++)
		{
			if (bot2[n].getX() == player.get_x() && bot2[n].getY() == player.get_y())
			{
				player.set_life(player.get_life() - 1);
				bot2[n].kill(1);
			}
		}
		for (n = 0; n < 5; n++)
		{
			if (bot3[n].getX() == player.get_x() && bot3[n].getY() == player.get_y())
			{
				player.set_life(player.get_life() - 1);
				bot3[n].kill(1);
			}
		}
		wattron(map.get_map(), COLOR_PAIR(1));
		mvwprintw(map.get_map() ,player.get_y(), player.get_x(), " ");
		rs_control(&player, bullet, bullet_num);
		rs_menu(&menu, &player, 1);
		mvwprintw(map.get_map() ,player.get_y(), player.get_x(), "}");
		wattron(map.get_map(), A_BOLD);
		wattroff(map.get_map(), COLOR_PAIR(1));
		box(map.get_map(), 0, 0);
		if (i % 40 == 0)
		{
			for (n = 0; n < 30; n++)
			{
				if (bot1[n].getY() != -1)
					bot1[n].changeTheCoords();
			}
		}
		if (i == 120)
		{
			for (n = 0; n < 15; n++)
			{
				if (bot2[n].getY() != -1)
					bot2[n].changeTheCoords();
			}
			for (n = 0; n < 5; n++)
			{
				if (bot3[n].getY() != -1)
					bot3[n].changeTheCoords();
			}
			i = 0;
		}
		if (i % 20 == 0)
		{
			for (n = 0; n < bullet_num; n++)
			{
				if (bullet[n].getY() != -1)
					bullet[n].move();
			}
		}
		wattron(map.get_map(), COLOR_PAIR(5));
		for (n = 0; n < 30; n++)
		{
			if (bot1[n].getY() != -1)
				mvwprintw(map.get_map() ,bot1[n].getY(), bot1[n].getX(), bot1[n].getChar());
		}
		wattron(map.get_map(), COLOR_PAIR(4));
		for (n = 0; n < 15; n++)
		{
			if (bot2[n].getY() != -1)
				mvwprintw(map.get_map() ,bot2[n].getY(), bot2[n].getX(), bot2[n].getChar());
		}
		wattron(map.get_map(), COLOR_PAIR(3));
		for (n = 0; n < 5; n++)
		{
			if (bot3[n].getY() != -1)
				mvwprintw(map.get_map() ,bot3[n].getY(), bot3[n].getX(), bot3[n].getChar());
		}
		wattroff(map.get_map(), COLOR_PAIR(3));
		for (n = 0; n < bullet_num; n++)
		{
			if (bullet[n].getY() != -1)
				mvwprintw(map.get_map() ,bullet[n].getY(), bullet[n].getX(), "-");
		}
		// int     t;
		// t = -1;
		// for (n = 1; n < 29; n++)
		// {
		// 	for (k = 1; k < 119; k++)
		// 	{
		// 		mvwprintw(map.get_map() ,n, k, (star[++t].getVisibility() == 1 ? "." : " "));
		// 	}
		// }
		wrefresh(map.get_map());
		i++;
		j++;
		if (bots1_num != 0 || bots2_num != 0 || bots3_num != 0)
			l++;
	}
	endwin();
	return (0);
}


