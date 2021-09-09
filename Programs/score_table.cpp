/*
- Accept number of rounds, static payload weight and sigma
- Convert values to pounds
- Calculate B_PADA term
- Check autonomy and change A_PADA and A_GTV
- Calculate y1
- Calculate y2 term
- Calculate y2 based on term
- Print values in terminal table
*/

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

float W_payload, W_delivered[100], B_PADA[100], W_payload_pounds;
float y_1[100][100], y_2[100][100][100];
float sum[100][100];
float A_GTV, A_PADA, N_PADA, sigma;

void convert_to_pounds()
{
    W_payload_pounds = W_payload * 2.204623;
    for (int i = 0; i <= W_payload; i++)
        W_delivered[i] *= 2.204623;
}

void accept_data()
{
    cout << "Enter number of PADA FLights: ";
    cin >> N_PADA;
    cout << "Enter static payload weight in kg: ";
    cin >> W_payload;
    cout << "Enter the standard deviation from TDS: ";
    cin >> sigma;
    for (int i = 0; i <= W_payload; i++)
        W_delivered[i] = i;
    convert_to_pounds();
}

void check_autonomy(int i)
{
    switch (i)
    {
    case 0: // FA
        A_PADA = 1.5;
        A_GTV = 2.0;
        break;
    case 1: // PADA-A
        A_PADA = 1.5;
        A_GTV = 1.5;
        break;
    case 2: // GTV-A
        A_PADA = 0.25;
        A_GTV = 2.0;
        break;
    case 3: // FM
        A_PADA = 0.25;
        A_GTV = 1.5;
        break;
    }
}

void calculate_B_pada()
{
    float pi, e;
    pi = 3.1415926535897;
    e = 2.7182818284590;
    for (int d = 0; d <= 15; d++)
    {
        B_PADA[d] = 5 * (1 / (sigma * pow(2 * pi, 0.5))) * pow(e, -(d * d / (2 * sigma * sigma)));
    }
}

void calculate_y1()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= W_payload; j++)
        {
            check_autonomy(i);
            y_1[i][j] = (W_payload_pounds + A_GTV * W_delivered[j]) / 4;
        }
    }
}

void calculate_y2_term()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= 15; j++)
        {
            check_autonomy(i);
            sum[i][j] = A_PADA + B_PADA[j];
        }
    }
}

void calculate_y2()
{
    for (int i = 0; i < N_PADA; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k <= 15; k++)
            {
                y_2[i][j][k] = 4 * (i + 1) * sum[j][k];
            }
        }
    }
}

void print_score_dependencies()
{
    cout << setw(260) << "Score Equation Optimisation" << endl;
    cout << setw(262) << "===============================" << endl
         << endl;
    cout << "Sigma from TDS: " << sigma << endl;
    cout << "Initial Payload Weight: "
         << W_payload
         << " Kg" << endl
         << endl;
    cout << setw(36) << "Weight Delivered(Kg)"
         << "  |  "
         << "Distance from center(ft)"
         << "  |  "
         << "GTV & PADA-Auto-Score"
         << "  |  "
         << "PADA-Auto-Score"
         << "  |  "
         << "GTV-Auto-Score"
         << "  |  "
         << "PADA & GTV-Man-Score" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void print_score()
{
    for (int i = 0; i < N_PADA; i++)
    {
        cout << "Round " << i + 1 << "\t";
        for (int j = 0; j <= W_payload; j++)
        {
            if (j != 0)
                cout << setw(15);
            cout << "\t\t" << j;
            for (int k = 0; k <= 15; k++)
            {
                if (k != 0)
                {
                    cout << setw(27);
                }
                cout << "\t\t\t" << k << "\t\t\t" << y_1[0][j] + y_2[i][0][k] << "\t\t\t" << y_1[1][j] + y_2[i][1][k] << "\t\t\t" << y_1[2][j] + y_2[i][2][k] << "\t\t\t" << y_1[3][j] + y_2[i][3][k] << endl;
            }
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout << endl;
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------";
        cout << endl;
    }
}

int main()
{
    accept_data();
    calculate_B_pada();
    calculate_y1();
    calculate_y2_term();
    calculate_y2();
    print_score_dependencies();
    print_score();
    while (1)
        ;
    return 0;
}