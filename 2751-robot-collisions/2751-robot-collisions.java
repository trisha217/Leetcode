class Solution {

    class Robot {
        int index;
        char direction;
        int health;
        int position;

        public Robot(int index, char direction, int health, int position) {
            this.index = index;
            this.direction = direction;
            this.health = health;
            this.position = position;
        }

        public int getHealth() {
            return this.health;
        }
    }

    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        Robot[] robots = new Robot[positions.length];

        for (int i = 0; i < positions.length; i++) {
            Robot robot = new Robot(i, directions.charAt(i), healths[i], positions[i]);
            robots[i] = robot;
        }

        Arrays.sort(robots, (a, b) -> {
            return a.position - b.position;
        });

        Stack<Robot> stack = new Stack<>();

        for (Robot robot : robots) {
            if (stack.isEmpty()) {
                stack.push(robot);
            } else if (willCollide(stack.peek(), robot)) {
                while (!stack.isEmpty() && willCollide(stack.peek(), robot)) {
                    Robot prevRobot = stack.pop();
                    if (prevRobot.health > robot.health) {
                        prevRobot.health--;
                        stack.push(prevRobot);
                        robot.health = 0;
                        break;
                    } else if (robot.health > prevRobot.health) {
                        robot.health--;
                        prevRobot.health = 0;
                    } else {
                        prevRobot.health = 0;
                        robot.health = 0;
                        break;
                    }
                }

                if (robot.health > 0) {
                    stack.push(robot);
                }
            } else {
                stack.push(robot);
            }
        }

        List<Robot> survivedRobots = new ArrayList<>();
        while (!stack.isEmpty()) {
            survivedRobots.add(stack.pop());
        }

        survivedRobots.sort((a, b) -> {
            return a.index - b.index;
        });

        return survivedRobots.stream().map(Robot::getHealth).toList();
    }

    public boolean willCollide(Robot robot1, Robot robot2) {
        return robot1.direction == 'R' && robot2.direction == 'L';
    }
}