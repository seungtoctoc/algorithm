import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);
    static Team[] teamInfos;

    public static void main(String[] args){
        int times = getTestNum();

        for (int i = 0 ; i < times ; i++) {
            int myTeam = getInputAndTotalScore();
            System.out.println(getRank(myTeam));
        }
    }

    static int getTestNum(){
        int times = scanner.nextInt();

        return times;
    }
    static int getInputAndTotalScore(){
        int teams = scanner.nextInt();
        int questions = scanner.nextInt();
        int myTeam = scanner.nextInt();
        int logs = scanner.nextInt();

        int[][] pastScore = new int[teams + 1][questions + 1];
        teamInfos = new Team[teams + 1];

        for (int i = 1 ; i <= teams ; i++) {
            Team team = new Team(0,0,-1);
            teamInfos[i] = team;
        }

        for (int i = 0 ; i < logs ; i++) {
            int team = scanner.nextInt();
            int question = scanner.nextInt();
            int score = scanner.nextInt();

            teamInfos[team].addSubmit();
            teamInfos[team].updateLastSubmitTime(i);
            if (pastScore[team][question] < score) {
                teamInfos[team].addScore(score - pastScore[team][question]);
                pastScore[team][question] = score;
            }
        }

        return myTeam;
    }

    static int getRank(int myTeam) {
        int rank = 1;
        int myScore = teamInfos[myTeam].getScore();
        int mySubmit = teamInfos[myTeam].getSubmit();
        int myLastSubmitTime = teamInfos[myTeam].getLastSubmitTime();

        for (int i = 1 ; i < teamInfos.length ; i++) {
            if (i == myTeam) {
                continue;
            }

            if (teamInfos[i].getScore() > myScore) {
                rank++;
                continue;
            }

            if (teamInfos[i].getScore() < myScore) {
                continue;
            }

            if (teamInfos[i].getSubmit() < mySubmit) {
                rank++;
                continue;
            }

            if (teamInfos[i].getSubmit() > mySubmit) {
                continue;
            }

            if (teamInfos[i].getLastSubmitTime() < myLastSubmitTime) {
                rank++;
            }
        }

        return rank;
    }

    static class Team {
        int score;
        int submit;
        int lastSubmitTime;

        public Team (int score, int submit, int lastSubmitTime) {
            this.score = score;
            this.submit = submit;
            this.lastSubmitTime = lastSubmitTime;
        }

        public void addScore(int score) {
            this.score += score;
        }

        public void addSubmit() {
            this.submit++;
        }

        public void updateLastSubmitTime(int time) {
            this.lastSubmitTime = time;
        }

        public int getScore() {
            return score;
        }

        public int getSubmit() {
            return submit;
        }

        public int getLastSubmitTime() {
            return lastSubmitTime;
        }
    }
}