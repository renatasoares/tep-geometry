#include <bits/stdc++.h>

using namespace std;

int main(){
    int teste = 0;
    int length;
    char direction_1, direction_2;
    double x, y;
    while (cin >> length){
        teste++;
        x = 0;
        y = 0;
        do
        {
            cin.get(direction_1);
            cin.get(direction_2);
            if (direction_2 == ',' || direction_2 == '.')
            {
                switch (direction_1)
                {
                case 'E':
                    x += length;
                    break;
                case 'S':
                   	y -= length;
                    break;
                case 'W':
                    x -= length;
                    break;
                case 'N':
                    y += length;
                    break;
                }
            }
            else
            {
                if (direction_1 == 'S')
                {
                    if (direction_2 == 'E')
                    {
                        x += length * (sqrt(2)/2);
						y -= length * (sqrt(2)/2);
                    }
                    else
                    {
                      	x -= length * (sqrt(2)/2);
						y -= length * (sqrt(2)/2);
                    }
                }
                else
                {
                    if (direction_2 == 'E')
                    {
                        x += length * (sqrt(2)/2);
						y += length * (sqrt(2)/2);
                    }
                    else
                    {
                        x -= length * (sqrt(2)/2);
						y += length * (sqrt(2)/2);
                    }
                }
                cin.get(direction_2);

            }
        }
        while (direction_2 != '.' && cin >> length);

		printf("Map #%d\n", teste);
		printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
		printf("The distance to the treasure is %.3lf.\n\n", sqrt(x*x + y*y));

    }
    return 0;
}
