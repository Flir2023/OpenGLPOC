#ifndef video_reader_hpp
#define video_reader_hpp

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#include <libswscale/swscale.h>
#include <inttypes.h>
#include <libavfilter/buffersink.h>  
#include <libavfilter/buffersrc.h>
#include <libavutil/opt.h>
#include <libavutil/pixdesc.h>
#include <libavutil/pixfmt.h>
#include <libavutil/timecode.h>
#include <libavutil/bprint.h>
#include <libavutil/time.h>
#include <libavutil/common.h>
#include <libavutil/imgutils.h>
#include <libavutil/colorspace.h>
}

struct VideoReaderState {
    // Public things for other parts of the program to read from
    int width, height;
    AVRational time_base;

    // Private internal state
    AVFormatContext* av_format_ctx;
    AVCodecContext* av_codec_ctx;
    int video_stream_index;
    AVFrame* av_frame;
    AVPacket* av_packet;
    SwsContext* sws_scaler_ctx;
};

AVFrame* OpenImage(const char*);
bool video_reader_open(VideoReaderState* state, const char* filename);
bool video_reader_read_frame(VideoReaderState* state, uint8_t* frame_buffer, int64_t* pts);
bool video_reader_seek_frame(VideoReaderState* state, int64_t ts);
void video_reader_close(VideoReaderState* state);
bool load_frame(const char* filename, int* width_out, int* height_out, unsigned char** data_out);

#endif
