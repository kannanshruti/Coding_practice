// https://leetcode.com/problems/keys-and-rooms/description/

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms);
    void check_room(vector<vector<int>>& rooms, vector<bool>& visited_rooms, int room_no);
};

bool Solution::canVisitAllRooms(vector<vector<int>>& rooms) {
    /* Checks whether every room can be visited. A room can be visited if 
    its key was previously obtained from another room
    Checking begins at room 0 which is assumed to be open

    @param: "rooms": Each index of this vector represents a room
                     Each index contains another vector listing the keys
                     present in this room
    @return: boolean: Whether all rooms were accessible or not
    */
    vector<bool> visited_rooms(rooms.size(), false);
    check_room(rooms, visited_rooms, 0);

    // Check if any room was left unvisited
    for (int i = 0; i < visited_rooms.size(); i++) 
        if (visited_rooms[i] == false) return false;
    return true;
}
void Solution::check_room(vector<vector<int>>& rooms, vector<bool>& visited_rooms, int room_no) {
    /* Checks whether "room_no" in "rooms" can be visited.
    @param: "rooms"         : Contains the room and key information
            "visited_rooms" : Set to 'true' if room key was present and room can be visited
            "room_no"       : Current room which is being visited and whose keys are being obtained
    @return: Updates "visited_rooms" with room visit status
    */
    if (visited_rooms[room_no] == true) return;
    visited_rooms[room_no] = true;
    
    for (int i = 0; i < rooms[room_no].size(); i++) // Loop through keys
        check_room(rooms, visited_rooms, rooms[room_no][i]); // Check rooms whose keys were obtained
}

int main() {
    Solution sol1;
    vector< vector<int> > input = {{1},{2},{3},{}};
    bool count = sol1.canVisitAllRooms(input);
    cout << count << "\n";
    return 0;
}