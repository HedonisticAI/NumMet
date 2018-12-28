double calcSecond(double x1, double x2)
{
return cos(x1 - 1) + x2 - 0.7;
}
int main()
{
setlocale(LC_CTYPE, "");
cout << "Решение Систем Неинейных Уравнений с точностью 0.001 \n\tМетодом n\n\tМетодом tМетодом
Итераций" << endl << endl;
cout << "Система уравнений:\n\tМетодом nf(x1) = 2x1+sin(x2)-2 = 0\n\tМетодом nf(x2) = cos(x1 - 1) + x2 - 0.7 =
0" << endl << endl;
const int SIZE = 2;
long double vec[SIZE];
vec[0] = 1.0;
vec[1] = 0.1;
double matrix[SIZE][SIZE];
double iterArr[100][SIZE];
for (int i = 0; i < 100; ++i)
for (int j = 0; j < SIZE; ++j)
{
iterArr[i][j] = 0;
}
iterArr[0][0] = First(vec[1]);
iterArr[0][1] = Second(vec[0]);
cout << "N\n\tМетодом t" << "X1\n\tМетодом t" << "X2\n\tМетодом t\n\tМетодом t" << "Max" << endl;
cout << "0\n\tМетодом t" << vec[0] << " " << vec[1] << endl;
cout << "1\n\tМетодом t" << iterArr[0][0] << " " << iterArr[0][1] << endl;
int n = 1;
double max = 0;
double max1 = 0;
double max2 = 0;
for (int c = 1;; c++)
{
for (int i = 0; i < SIZE; ++i)
{
if (i == 0)
iterArr[c][0] = First(iterArr[c - 1][1]);
if (i == 1) iterArr[c][1] = Second(iterArr[c - 1][0]);
if (i == 0)
{
cout << c + 1 << "\n\tМетодом t";
double k1 = fabs(iterArr[c][i] - iterArr[c - 1][i]);
if (k1 > max1) max1 = k1;
}
if (i == 1)
{
double k2 = fabs(iterArr[c][i] - iterArr[c - 1][i]);
if (k2 > max2) max2 = k2;
}
double k = fabs(iterArr[c][i] - iterArr[c - 1][i]);
if (k > max) max = k;
cout.setf(ios::fixed);
