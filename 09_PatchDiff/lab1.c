#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void make_route(int cx, int cy, char *maze, int totalWidth, int totalHeight,
                char wall, char space) {
  static const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int directions_order[4] = {0, 1, 2, 3};
  for (int i = 0; i < 4; i++) {
    int r = rand() % 4;
    int temp = directions_order[i];
    directions_order[i] = directions_order[r];
    directions_order[r] = temp;
  }

  for (int i = 0; i < 4; i++) {
    int wx = cx + directions[directions_order[i]][0];
    int wy = cy + directions[directions_order[i]][1];

    int nx = cx + directions[directions_order[i]][0] * 2;
    int ny = cy + directions[directions_order[i]][1] * 2;

    if (nx > 0 && nx < totalWidth && ny > 0 && ny < totalHeight &&
        maze[ny * totalWidth + nx] == wall) {
      maze[ny * totalWidth + nx] = space;
      maze[wy * totalWidth + wx] = space;

      make_route(nx, ny, maze, totalWidth, totalHeight, wall, space);
    }
  }
}

void generate_maze() {
  const int width = 6;
  const int height = 6;
  const int totalWidth = width * 2 + 1;
  const int totalHeight = height * 2 + 1;
  const char wall = '#';
  const char space = '.';

  char maze[totalHeight * totalWidth];
  memset(maze, wall, totalHeight * totalWidth);

  const int startX = 1;
  const int startY = 1;

  maze[startY * totalWidth + startX] = space;
  make_route(startX, startY, maze, totalWidth, totalHeight, wall, space);

  for (int y = 0; y < totalHeight; y++) {
    for (int x = 0; x < totalWidth; x++) {
      printf("%c", maze[y * totalWidth + x]);
    }
    printf("\n");
  }
}

int main(void) {
  srand(time(NULL));
  generate_maze();
  return 0;
}