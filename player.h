#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

#include "mme.h"

namespace MME{

class Player : QObject
{
    Q_OBJECT
public:
    Player();

    void stop();
    void play();
    void pause();
    void seek(qint64 timestamp);
    qint64 totalTimestamp() const;
    qint64 currentTimestamp() const;

    MME::EPlayerState playerState() const;
    MME::EResourceType resourceType() const;

private:
    qint64 mTotalTimestamp;
    qint64 mCurrentTimestamp;
    MME::EPlayerState mPlayerState;
    MME::EResourceType mResourceType;
};

}
#endif // PLAYER_H
