char* add(char *a, char *b) {
	int al = 0, bl = 0, cr = 0;
	while (a[++al]);
	while (b[++bl]);
	--al; --bl;
	int cl = al > bl ? al : bl;
	char *tmp = new char[cl+1]();

	while (al >= 0 || bl >= 0 || cr) {
		if (al >= 0) cr += a[al--] - '0';
		if (bl >= 0) cr += b[bl--] - '0';
		tmp[--cl] = cr % 10 + '0';
		cr = cr / 10;
	}
	return tmp + cl;
}