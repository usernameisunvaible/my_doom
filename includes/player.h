typedef struct 
{
    sfBool top;
    sfBool bottom;
    sfBool left;
    sfBool right;
    sfBool c_left;
    sfBool c_right;
}movement_;

typedef struct {
    sfVector2i pos;
    int angle;
    sfVertexArray **rays;
    sfBool *hit;
    movement_ *move;
    sfVector2f vec_dir;
    sfVector2f vec_dir_side;
}player_;

