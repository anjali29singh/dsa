/*A car travels from a starting position to a destination which is target miles east of the starting position.

There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived*/

// method 1 dp
// method 2 priority queue

#include <bits/stdc++.h>
using namespace std;

int minFuelStops(vector<vector<int>> &stations, int startFuel, int target)
{

    int n = stations.size();
    priority_queue<int> pq;
    int curr = startFuel;
    int i = 0;
    int ans = 0;
    while (curr < target)
    {

        while (i < n && curr >= stations[i][0])
        {
            // stores stations  for future use when we don't have any fuel and need station having maximum fuel
            pq.push(stations[i][1]);
            i++;
        }

        if (pq.empty())
            return -1;

        int dist = pq.top();

        curr += dist;
        ans++;
    }
    return ans;
}
int main()
{

    return 0;
}