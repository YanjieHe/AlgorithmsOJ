class Solution {
    public void visit(boolean[] visited, List<List<Integer>> rooms, int index) {
        if(visited[index]) {
            return;
        } else {
            List<Integer> room = rooms.get(index);
            visited[index] = true;
            for(Integer key: room) {
                visit(visited, rooms, key);
            }
        }
    }
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] visited = new boolean[rooms.size()];
        for(int i = 0; i < visited.length; i++) {
            visited[i] = false;
        }
        visit(visited, rooms, 0);
        for(boolean room: visited) {
            if(room == false) {
                return false;
            }
        }
        return true;
    }
}
