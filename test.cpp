int hours, minutes, seconds; //current time variables
int elap_h, elap_m, elap_s; //elapsed time variables
int future_h, future_m, future_s; //future time variables

seconds + elap_s = future_s;
if (future_s >= 60)
{
	elap_m + 1;
	future_s = future_s - 60;
}

minutes + elap_m = future_m;
if (future_m >= 60)
{
	elap_h + 1;
	future_m = future_m - 60;
}
hours + elap_h = future_h;
if (future_h >= 24)
{
	future_h = future_h - 24;
}