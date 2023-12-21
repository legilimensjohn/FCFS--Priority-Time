#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    const int n = 7;  // Specify the number of processes
    int avwt = 0, avtat = 0;

    int id[n], at[n], bt[n], pt[n], wt[n] = {0}, tat[n] = {0};

    cout << "\nPlease provide the arrival time and duration for all processes individually!\n";

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        cout << "P[" << id[i] << "] Arrival Time: ";
        cin >> at[i];
        cout << "P[" << id[i] << "] Burst Time: ";
        cin >> bt[i];
        cout << "P[" << id[i] << "] Priority Time: ";
        cin >> pt[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[j] < at[i]) {
                int temp = id[i];
                id[i] = id[j];
                id[j] = temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pt[i];
                pt[i] = pt[j];
                pt[j] = temp;
            }
        }
    }
    int ct = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = j + 1; k <= i; k++) {
                if (pt[k] < pt[j]) {
                    int temp = id[j];
                    id[j] = id[k];
                    id[k] = temp;
                    temp = at[j];
                    at[j] = at[k];
                    at[k] = temp;
                    temp = bt[j];
                    bt[j] = bt[k];
                    bt[k] = temp;
                    temp = pt[j];
                    pt[j] = pt[k];
                    pt[k] = temp;
                }
            }
        }
        wt[i] = max(0, ct - at[i]);

        tat[i] = wt[i] + bt[i];
        ct += bt[i];
    }
    cout << "\nProcess\tArrival Time\tBurst Time\tPriority Time\tWaiting Time\tTurnaround Time";
    for (int i = 0; i < n; i++) {
        avwt += wt[i];
        avtat += tat[i];
        cout << "\nP[" << id[i] << "]\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << pt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }
   
}
