class Singleton
{
private:

    int PlayerSpeed;
    int ScreenBottom;
    int ScreenTop;
    bool menu;
    bool CloseGame;
public:
    bool isCloseGame() const;

    void setCloseGame(bool closeGame);

public:


public:
    bool isMenu() const;

    void setMenu(bool menu);

public:
    int getScreenTop() const;

    void setScreenTop(int screenTop);

private:
    int Rocket;
public:
    int getRocket() const;

    void setRocket(int rocket);

private:

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


