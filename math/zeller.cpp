int zeller(int yy, int m, int d) {
	if (m<=2) m+=12, --yy;
	int y = yy%100;
	int c = yy/100;

	return (d + 13*(m+1)/5 + y + y/4 + c/4 + 5*c) % 7;
}

/*
0 : Saturday
1 : Sunday
2 : Monday
3 : Tuesday
4 : Wednesday
5 : Thursday
6 : Friday
*/