#include "t_1_hellowffmpeg.h"

#include <QDebug>

T_1_HellowFFmpeg::T_1_HellowFFmpeg()
{

}

QList<QString>& T_1_HellowFFmpeg::ffmpeg_support_in_protocol()
{
    this->mInProtocols.clear();

    // ffmpeg注册复用器，编码器等的函数av_register_all()。该函数在所有基于ffmpeg的应用程序中几乎都是第一个被调用的。只有调用了该函数，才能使用复用器，编码器等
    av_register_all();
    struct URLProtocol *pt = NULL;
    struct URLProtocol **opaque = &pt;
    const char* protocol = "";
    protocol = avio_enum_protocols((void **)opaque, 0);
    while((*opaque) !=  NULL)
    {
        QString protocolName(protocol);
        qDebug() << "[IN-PROTOCOL] - " << protocolName;
        if(!protocolName.isEmpty())
        {
            this->mInProtocols.append(protocolName);
        }
        protocol = avio_enum_protocols((void **)opaque, 0);
    }

    return this->mInProtocols;
}

QList<QString>& T_1_HellowFFmpeg::ffmpeg_support_out_protocol()
{
    this->mOutProtocols.clear();
    // ffmpeg注册复用器，编码器等的函数av_register_all()。该函数在所有基于ffmpeg的应用程序中几乎都是第一个被调用的。只有调用了该函数，才能使用复用器，编码器等
    av_register_all();
    struct URLProtocol *pt = NULL;
    struct URLProtocol **opaque = &pt;
    const char* protocol = "";

    protocol = avio_enum_protocols((void**)opaque, 1);
    while((*opaque) !=  NULL)
    {
        QString protocolName(protocol);
        qDebug() << "[OUT-PROTOCOL] - " << protocolName;
        if(!protocolName.isEmpty())
        {
            this->mOutProtocols.append(protocolName);
        }
        protocol = avio_enum_protocols((void **)opaque, 1);
    }

    return this->mOutProtocols;
}

QList<QString>& T_1_HellowFFmpeg::ffmpeg_support_in_avformat()
{
    this->mInAvformats.clear();
    // ffmpeg注册复用器，编码器等的函数av_register_all()。该函数在所有基于ffmpeg的应用程序中几乎都是第一个被调用的。只有调用了该函数，才能使用复用器，编码器等
    av_register_all();

    // first
    AVInputFormat *i_tmp = av_iformat_next(NULL);
    while(i_tmp != NULL)
    {
        //
        QString iFormatName(i_tmp->name);
        qDebug() << "[IN-AVFORMAT] - " << iFormatName;
        if(!iFormatName.isEmpty())
        {
            this->mInAvformats.append(iFormatName);
        }
        i_tmp = i_tmp->next;
    }

    return mInAvformats;
}

QList<QString>& T_1_HellowFFmpeg::ffmpeg_support_out_avformat(){
    this->mOutAvformats.clear();
    // ffmpeg注册复用器，编码器等的函数av_register_all()。该函数在所有基于ffmpeg的应用程序中几乎都是第一个被调用的。只有调用了该函数，才能使用复用器，编码器等
    av_register_all();

    // first format
    AVOutputFormat *o_tmp = av_oformat_next(NULL);
    while(o_tmp != NULL)
    {
        //
        QString oFormatName(o_tmp->name);
        qDebug() << "[OUT-AVFORMAT] - " << oFormatName;
        if(!oFormatName.isEmpty())
        {
            mOutAvformats.append(oFormatName);
        }

        // next
        o_tmp = o_tmp->next;
    }

    return mOutAvformats;
}

QList<QString>& T_1_HellowFFmpeg::ffmpeg_support_encoder()
{
    this->mEncoders.clear();

    av_register_all();

    AVCodec *tmp = av_codec_next(NULL);
    while(tmp != NULL)
    {
        //
        QString name(tmp->name);
        //
        if(tmp->decode == NULL && !name.isEmpty())
        {
            qDebug()<<QObject::tr("[ENCODER]%1%2%3").arg(tmp->type == AVMEDIA_TYPE_VIDEO ? "[VIDEO]" : "").arg(tmp->type == AVMEDIA_TYPE_AUDIO ? "[AUDIO]" : "").arg(((tmp->type != AVMEDIA_TYPE_VIDEO)&&(tmp->type != AVMEDIA_TYPE_AUDIO)) ? "[OTHER]" : "")<< name;

            this->mEncoders.append(name);
        }

        tmp = tmp->next;
    }

    return this->mEncoders;
}

QList<QString>& T_1_HellowFFmpeg::ffmpeg_support_decoder()
{
    this->mDecoders.clear();
    av_register_all();

    AVCodec *tmp = av_codec_next(NULL);
    while(tmp != NULL)
    {
        //
        QString name(tmp->name);
        //
        if(tmp->decode != NULL && !name.isEmpty())
        {
            qDebug()<<QObject::tr("[DECODER]%1%2%3").arg(tmp->type == AVMEDIA_TYPE_VIDEO ? "[VIDEO]" : "").arg(tmp->type == AVMEDIA_TYPE_AUDIO ? "[AUDIO]" : "").arg(((tmp->type != AVMEDIA_TYPE_VIDEO)&&(tmp->type != AVMEDIA_TYPE_AUDIO)) ? "[OTHER]" : "")<< name;
            this->mDecoders.append(name);
        }

        tmp = tmp->next;
    }

    return this->mDecoders;
}
