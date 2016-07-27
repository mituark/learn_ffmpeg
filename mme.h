#ifndef MME_H
#define MME_H

#include <QString>
namespace MME
{
class MME
{
public:
    // global string defines
    static QString AppName(){return "MME";}
    static QString Company(){return "Gwe";}
    static QString Package(){return "com.gwecom.mme";}
    static QString VersionCode(){return "1.0.0";}

    static QString GStyleSheetFilePath(){return ":/stylesheet.qss";}

    // global enums
    enum EPlayerState
    {
        PlayerStateNone = -1,
        Stopped,
        Playing,
        Paused
    };

    enum EResourceType
    {
        ResourceTypeNone = -1,
        AudioResource,
        VideoResurce
    };

    // global params

    // global macros
};

}
#endif // MME_H
