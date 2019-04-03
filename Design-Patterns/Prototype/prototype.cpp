#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

using namespace std;

class Bullet
{
protected:
    string _bulletName;
    float  _speed;
    float  _firePower;
    float  _damagePower;
    float  _direction;

public:
    Bullet() {}
    Bullet(string bulletName, float speed, float firePower, float damagePower)
    : _bulletName(bulletName), _speed(speed), _firePower(firePower), _damagePower(damagePower) {}

    virtual ~Bullet() {}
    virtual unique_ptr<Bullet> clone() = 0;
    void fire(float direction)
    {
        _direction = direction;

        cout << "Name        : " << _bulletName << endl
             << "Speed       : " << _speed << endl
             << "FirePower   : " << _firePower << endl
             << "DamagePower : " << _damagePower << endl
             << "Direction   : " << _direction << endl << endl;
    }
};

class SimpleBullet : public Bullet
{
public:
    SimpleBullet(string bulletName, float speed, float firePower, float damagePower)
    : Bullet(bulletName, speed, firePower, damagePower) {}

    unique_ptr<Bullet> clone() override
    {
        return make_unique<SimpleBullet>(*this);
    }
};

class GoodBullet : public Bullet
{
public:
    GoodBullet(string bulletName, float speed, float firePower, float damagePower)
    : Bullet(bulletName, speed, firePower, damagePower) {}

    unique_ptr<Bullet> clone() override
    {
        return make_unique<GoodBullet>(*this);
    }
};

enum class BulletType
{
    SIMPLE,
    GOOD
};

class BulletFactory
{
private:
    unordered_map<BulletType, unique_ptr<Bullet>> m_Bullets;

public:
    BulletFactory()
    {
        m_Bullets[BulletType::SIMPLE] = make_unique<SimpleBullet>("Simple Bullet", 50, 75, 75);
        m_Bullets[BulletType::GOOD] = make_unique<GoodBullet>("Good Bullet", 75, 100, 100);
    }

    unique_ptr<Bullet> createBullet(BulletType bulletType)
    {
        return m_Bullets[bulletType]->clone();
    }
};

int main()
{
    BulletFactory bulletFactory;

    auto bullet = bulletFactory.createBullet(BulletType::SIMPLE);
    bullet->fire(90);

    bullet = bulletFactory.createBullet(BulletType::GOOD);
    bullet->fire(100);

    return 0;
}
