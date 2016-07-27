#ifndef T_1_HELLOWFFMPEG_H
#define T_1_HELLOWFFMPEG_H

// 1. Protocol 协议
// 2. AVFormat 封装格式
// 3. AVCodec 编解码器

extern "C"{
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
}

#include <QList>

class T_1_HellowFFmpeg
{
public:
    T_1_HellowFFmpeg();

    // supprt protocol
    QList<QString> &ffmpeg_support_in_protocol();
    QList<QString> &ffmpeg_support_out_protocol();

    // support format
    QList<QString> &ffmpeg_support_in_avformat();
    QList<QString> &ffmpeg_support_out_avformat();

    //
    QList<QString> &ffmpeg_support_encoder();
    QList<QString> &ffmpeg_support_decoder();

    //
    void show_all_support_info()
    {
        ffmpeg_support_in_protocol();
        ffmpeg_support_out_protocol();
        ffmpeg_support_in_avformat();
        ffmpeg_support_out_avformat();
        ffmpeg_support_encoder();
        ffmpeg_support_decoder();
    }
private:
    QList<QString> mInProtocols;
    QList<QString> mOutProtocols;
    QList<QString> mInAvformats;
    QList<QString> mOutAvformats;
    QList<QString> mEncoders;
    QList<QString> mDecoders;
};

#endif // T_1_HELLOWFFMPEG_H
