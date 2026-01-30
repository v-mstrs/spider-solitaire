#include "raylib.h"
#include "solitaire.h"

Card cards[104];

void DrawCard(Texture2D texture, int row, int col, int tile_w, int tile_h, Vector2 pos)
{
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

void init()
{
    int i = 0;
    for (int deck = 0; deck < 2; deck++)
    {
        for (int rank = 1; rank <= 13; rank++)
        {
            for (int copy = 0; copy < 4; copy++)
            {
                cards[i].rank = rank;
                cards[i].suit = 3;
                cards[i].face_up = false;
                i++;
            }
        }
    }
}


int main(void)
{
    const int screen_width = 1280;
    const int screen_height = 720;

    float scale  = 2.0f;
    float card_w = 64 * scale;

    float total_width = screen_width;
    float spacing = (total_width - card_w) / 9;

    bool debug = false;

    Card card = { .rank = 1, .suit = 3, .face_up = false};

    InitWindow(screen_width , screen_height, "Spider Solitaire");
    SetTargetFPS(1);

    Image tilesheet = LoadImage("cardsLarge_tilemap_packed.png");
    Texture2D texture = LoadTextureFromImage(tilesheet);
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

            init();

            for (int i = 0; i < 104; i++)
            {
                printf("Card No. %d = %d\n", i, cards[i].rank);
            }
            /*for (int i = 0; i < 10; i++)
            {
                Vector2 draw_pos = {
                    card_pos.x + spacing * i,
                    card_pos.y
                };

                DrawCard(texture, 3, i, 64, 64, draw_pos);
            }*/

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
