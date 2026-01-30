#include <stdio.h>

#include "raylib.h"

void DrawCard(Texture2D texture, int row, int col, int tile_w, int tile_h, Vector2 pos)
{
    /*if (row < 0 || row > 4)
    {
        printf("Row can only be from 0 to 4\n");
        return;
    }
    if (col < 0 || col > 12)
    {
        printf("Column can only be from 0 to 13\n");
        return;
    }*/

    Rectangle src = {
        col * tile_w,
        row * tile_h,
        tile_w,
        tile_h
    };

    Rectangle dest_rec = {
        pos.x,
        pos.y,
        tile_w * 2.0f,
        tile_h * 2.0f
    };

    DrawTexturePro(texture, src, dest_rec, (Vector2){0, 0}, 0,  WHITE);
}


int main(void)
{
    const int screen_width = 1270;
    const int screen_height = 720;

    float scale  = 2.0f;
    float card_w = 64 * scale;

    float total_width = screen_width;
    float spacing = (total_width - card_w) / 9;

    bool debug = true;

    InitWindow(screen_width , screen_height, "Spider Solitaire");
    SetTargetFPS(6);

    Image tilesheet = LoadImage("cardsLarge_tilemap_packed.png");
    Texture2D texture = LoadTextureFromImage(tilesheet);      // Image converted to texture, uploaded to GPU memory (VRAM)
    UnloadImage(tilesheet);

    Vector2 card_pos = {0, 10};

    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        if (IsKeyPressed(KEY_ENTER))
            debug = !debug;

        if (debug)
            printf("x: %f y: %f\n", mouse.x, mouse.y);

        BeginDrawing();
            ClearBackground(DARKGREEN);

            for (int i = 0; i < 10; i++)
            {
                Vector2 draw_pos = {
                    card_pos.x + spacing * i,
                    card_pos.y
                };

                DrawCard(texture, 3, i, 64, 64, draw_pos);
            }

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
