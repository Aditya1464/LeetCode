class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        queue<int> q;
        sort(deck.begin(), deck.end());
        int i = deck.size() - 1;
        q.push(deck[i]);
        i--;

        while(i >= 0){
            int front = q.front();
            q.pop();
            q.push(front);
            q.push(deck[i]);
            i--;
        }

        i = 0;
        while(q.size() != 0){
            deck[i] = q.front();
            q.pop();
            i++;
        }

        reverse(deck.begin(), deck.end());

        return deck;
    }
};