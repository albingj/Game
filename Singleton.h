class Singleton
{
private:

    int PlayerSpeed;
    int ScreenBottom;

    /* Here will be the instance stored. */
    static Singleton* instance;

    /* Private constructor to prevent instancing. */
    Singleton();

public:
    /* Static access method. */
    static Singleton* getInstance();
    void setPlayerSpeed(int Speed);
    int getPlayerSpeed();
    int getScreenBottom();
};


