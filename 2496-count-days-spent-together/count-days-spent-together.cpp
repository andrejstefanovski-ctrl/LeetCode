class Solution {
public:
    int convertToDays(int n, int start) {
        int sum=start;
        for (int i=1; i<n; i++) {
            if (i==2) {
                sum+=28;
            }
            else if (i%2==0 && i<=7) {
                sum+=30;
            }
            else if (i%2!=0 && i<=7) {
                sum+=31;
            }
            else if (i%2==0 && i>7) {
                sum+=31;
            }
            else if (i%2!=0 && i>7) {
                sum+=30;
            }
        }
        return sum;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int monthAlice = (arriveAlice[0]-'0')*10 + (arriveAlice[1]-'0');
        int dayAlice = (arriveAlice[3]-'0')*10 + (arriveAlice[4]-'0');
        int monthAliceLeave = (leaveAlice[0]-'0')*10 + (leaveAlice[1]-'0');
        int dayAliceLeave = (leaveAlice[3]-'0')*10 + (leaveAlice[4]-'0');

        int monthBob = (arriveBob[0]-'0')*10 + (arriveBob[1]-'0');
        int dayBob = (arriveBob[3]-'0')*10 + (arriveBob[4]-'0');
        int monthBobLeave = (leaveBob[0]-'0')*10 + (leaveBob[1]-'0');
        int dayBobLeave = (leaveBob[3]-'0')*10 + (leaveBob[4]-'0');

        int comeAlice = convertToDays(monthAlice, dayAlice), goAlice = convertToDays(monthAliceLeave, dayAliceLeave);
        int comeBob = convertToDays(monthBob, dayBob), goBob = convertToDays(monthBobLeave, dayBobLeave);
        int startMeet=0, endMeet=0;
        if (comeAlice > goBob || comeBob > goAlice) {
            return 0;
        }
        if (comeAlice < comeBob) {
            startMeet = comeBob;
        }
        else if (comeAlice >= comeBob) {
            startMeet = comeAlice;
        }

        if (goAlice > goBob) {
            endMeet = goBob;
        }
        else if (goAlice <= goBob) {
            endMeet = goAlice;
        }
        return endMeet-startMeet+1;
    }
};