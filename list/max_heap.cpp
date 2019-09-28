vector<int> hp;

void push(int val) {
	hp.pb(val);

	int ci = hp.size() - 1;
	while (ci) {
		int ni = (ci - 1) / 2;
		if (hp[ci] > hp[ni]) {
			swap(hp[ci], hp[ni]);
			ci = ni;
		}
		else break;
	}
}

int pop() {
	if (hp.empty()) return 0;
	int ret = hp[0];
	hp[0] = hp.back();
	hp.pop_back();

	int ci = 0;
	while (true) {
		int ni = ci;
		int le = 2 * ci + 1;
		int ri = 2 * ci + 2;
		if (le < hp.size() && hp[ni] < hp[le]) ni = le;
		if (ri < hp.size() && hp[ni] < hp[ri]) ni = ri;

		if (ni == ci) break;
		swap(hp[ci], hp[ni]);
		ci = ni;
	}

	return ret;
}