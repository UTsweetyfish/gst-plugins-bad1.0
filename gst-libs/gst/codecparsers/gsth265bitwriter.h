/* GStreamer
 *  Copyright (C) 2021 Intel Corporation
 *     Author: He Junyan <junyan.he@intel.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the0
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_H265_BIT_WRITER_H__
#define __GST_H265_BIT_WRITER_H__

#include <gst/codecparsers/gsth265parser.h>
#include <gst/codecparsers/codecparsers-prelude.h>

G_BEGIN_DECLS

/**
 * GstH265BitWriterResult:
 * @GST_H265_BIT_WRITER_OK: The writing succeeded
 * @GST_H265_BIT_WRITER_INVALID_DATA: The input data to write is invalid
 * @GST_H265_BIT_WRITER_NO_MORE_SPACE: The output does not have enough size
 * @GST_H265_BIT_WRITER_ERROR: An general error occurred when writing
 *
 * The result of writing H265 data into bit stream.
 *
 * Since: 1.22
 */
typedef enum
{
  GST_H265_BIT_WRITER_OK,
  GST_H265_BIT_WRITER_INVALID_DATA,
  GST_H265_BIT_WRITER_NO_MORE_SPACE,
  GST_H265_BIT_WRITER_ERROR
} GstH265BitWriterResult;

GST_CODEC_PARSERS_API
GstH265BitWriterResult    gst_h265_bit_writer_vps      (const GstH265VPS * vps,
                                                        gboolean start_code,
                                                        guint8 * data,
                                                        guint * size);
GST_CODEC_PARSERS_API
GstH265BitWriterResult    gst_h265_bit_writer_sps      (const GstH265SPS * sps,
                                                        gboolean start_code,
                                                        guint8 * data,
                                                        guint * size);
GST_CODEC_PARSERS_API
GstH265BitWriterResult    gst_h265_bit_writer_pps      (const GstH265PPS * pps,
                                                        gboolean start_code,
                                                        guint8 * data,
                                                        guint * size);
GST_CODEC_PARSERS_API
GstH265BitWriterResult    gst_h265_bit_writer_slice_hdr (const GstH265SliceHdr * slice,
                                                         gboolean start_code,
                                                         guint32 nal_type,
                                                         guint8 * data,
                                                         guint * size);
GST_CODEC_PARSERS_API
GstH265BitWriterResult    gst_h265_bit_writer_sei       (GArray * sei_messages,
                                                         GstH265NalUnitType nal_type,
                                                         gboolean start_code,
                                                         guint8 * data,
                                                         guint * size);

GST_CODEC_PARSERS_API
GstH265BitWriterResult    gst_h265_bit_writer_aud       (guint8 pic_type,
                                                         gboolean start_code,
                                                         guint8 * data,
                                                         guint * size);

GST_CODEC_PARSERS_API
GstH265BitWriterResult    gst_h265_bit_writer_convert_to_nal (guint nal_prefix_size,
                                                              gboolean packetized,
                                                              gboolean has_startcode,
                                                              gboolean add_trailings,
                                                              const guint8 * raw_data,
                                                              gsize raw_size,
                                                              guint8 * nal_data,
                                                              guint * nal_size);
G_END_DECLS

#endif /* __GST_H265_BIT_WRITER_H__ */
