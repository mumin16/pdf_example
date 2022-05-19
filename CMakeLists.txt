cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
    set(SELECTDIR windows)
    set(SELECTSOURCE resource.rc)
    set(LIBRARIES mingw32)
elseif (UNIX)
    set(SELECTDIR linux)
    #set(LIBRARIES dl pthread)
elseif (APPLE)
    set(SELECTDIR macos)
    #set(LIBRARIES iconv)
endif ()
set(EXECUTABLE_OUTPUT_PATH "../bin")
set(CMAKE_C_FLAGS "-DHAVE_INTTYPES_H -DHAVE_STDINT_H -DHAVE_ZLIB -DMZ_ZIP_NO_CRYPTO -DMZ_ZIP_NO_ENCRYPTION -DZLIB_COMPAT -D_POSIX_C_SOURCE=200112L \
                -DZLIB_VERNUM=0x12c0")
include_directories(../third_party/include ../third_party/include/hpdfs/include ../third_party/include/${SELECTDIR})
link_directories(../third_party/lib/${SELECTDIR})

project(demo)
add_executable(demo  main.cpp

        ${SELECTSOURCE}

        ../third_party/include/zlib/adler32.c
        ../third_party/include/zlib/compress.c
        ../third_party/include/zlib/crc32.c
        ../third_party/include/zlib/deflate.c
        ../third_party/include/zlib/gzclose.c
        ../third_party/include/zlib/gzlib.c
        ../third_party/include/zlib/gzread.c
        ../third_party/include/zlib/gzwrite.c
        ../third_party/include/zlib/inflate.c
        ../third_party/include/zlib/infback.c
        ../third_party/include/zlib/inffast.c
        ../third_party/include/zlib/inftrees.c
        ../third_party/include/zlib/trees.c
        ../third_party/include/zlib/uncompr.c
        ../third_party/include/zlib/zutil.c

        ../third_party/include/minizip/mz_crypt.c
        ../third_party/include/minizip/mz_os.c
        ../third_party/include/minizip/mz_strm.c
        ../third_party/include/minizip/mz_strm_buf.c
        ../third_party/include/minizip/mz_strm_mem.c
        ../third_party/include/minizip/mz_strm_split.c
        ../third_party/include/minizip/mz_zip.c
        ../third_party/include/minizip/mz_zip_rw.c
        ../third_party/include/minizip/mz_strm_zlib.c
        ../third_party/include/minizip/mz_os_posix.c
        ../third_party/include/minizip/mz_strm_os_posix.c

        ../third_party/include/png/png.c                                                          
        ../third_party/include/png/pngerror.c                                                     
        ../third_party/include/png/pngget.c                                                    
        ../third_party/include/png/pngmem.c                                                       
        ../third_party/include/png/pngpread.c                                                    
        ../third_party/include/png/pngread.c                                                     
        ../third_party/include/png/pngrio.c                                                      
        ../third_party/include/png/pngrtran.c                                                    
        ../third_party/include/png/pngrutil.c                                                     
        ../third_party/include/png/pngset.c                                                      
        ../third_party/include/png/pngtrans.c                                                    
        ../third_party/include/png/pngwio.c                                                      
        ../third_party/include/png/pngwrite.c                                                   
        ../third_party/include/png/pngwtran.c                                                    
        ../third_party/include/png/pngwutil.c       

        ../third_party/include/hpdfs/src/hpdf_annotation.c
        ../third_party/include/hpdfs/src/hpdf_array.c                                                     
        ../third_party/include/hpdfs/src/hpdf_binary.c                                                     
        ../third_party/include/hpdfs/src/hpdf_boolean.c                                                    
        ../third_party/include/hpdfs/src/hpdf_catalog.c                                                    
        ../third_party/include/hpdfs/src/hpdf_destination.c                                                
        ../third_party/include/hpdfs/src/hpdf_dict.c                                                       
        ../third_party/include/hpdfs/src/hpdf_doc_png.c                                                    
        ../third_party/include/hpdfs/src/hpdf_doc.c                                                        
        ../third_party/include/hpdfs/src/hpdf_encoder_cns.c                                                
        ../third_party/include/hpdfs/src/hpdf_encoder_cnt.c                                                
        ../third_party/include/hpdfs/src/hpdf_encoder_jp.c                                                 
        ../third_party/include/hpdfs/src/hpdf_encoder_kr.c                                                 
        ../third_party/include/hpdfs/src/hpdf_encoder.c                                                    
        ../third_party/include/hpdfs/src/hpdf_encrypt.c                                                    
        ../third_party/include/hpdfs/src/hpdf_encryptdict.c                                                
        ../third_party/include/hpdfs/src/hpdf_error.c                                                      
        ../third_party/include/hpdfs/src/hpdf_ext_gstate.c                                                 
        ../third_party/include/hpdfs/src/hpdf_font_cid.c                                                   
        ../third_party/include/hpdfs/src/hpdf_font_tt.c                                                    
        ../third_party/include/hpdfs/src/hpdf_font_type1.c                                                 
        ../third_party/include/hpdfs/src/hpdf_font.c                                                       
        ../third_party/include/hpdfs/src/hpdf_fontdef_base14.c                                             
        ../third_party/include/hpdfs/src/hpdf_fontdef_cid.c                                                
        ../third_party/include/hpdfs/src/hpdf_fontdef_cns.c                                                
        ../third_party/include/hpdfs/src/hpdf_fontdef_cnt.c                                                
        ../third_party/include/hpdfs/src/hpdf_fontdef_jp.c                                                 
        ../third_party/include/hpdfs/src/hpdf_fontdef_kr.c                                                 
        ../third_party/include/hpdfs/src/hpdf_fontdef_tt.c                                                 
        ../third_party/include/hpdfs/src/hpdf_fontdef_type1.c                                              
        ../third_party/include/hpdfs/src/hpdf_fontdef.c                                                    
        ../third_party/include/hpdfs/src/hpdf_gstate.c                                                     
        ../third_party/include/hpdfs/src/hpdf_image_ccitt.c                                                
        ../third_party/include/hpdfs/src/hpdf_image_png.c
        ../third_party/include/hpdfs/src/hpdf_image.c
        ../third_party/include/hpdfs/src/hpdf_info.c
        ../third_party/include/hpdfs/src/hpdf_list.c
        ../third_party/include/hpdfs/src/hpdf_mmgr.c
        ../third_party/include/hpdfs/src/hpdf_name.c
        ../third_party/include/hpdfs/src/hpdf_namedict.c
        ../third_party/include/hpdfs/src/hpdf_null.c
        ../third_party/include/hpdfs/src/hpdf_number.c
        ../third_party/include/hpdfs/src/hpdf_objects.c
        ../third_party/include/hpdfs/src/hpdf_outline.c
        ../third_party/include/hpdfs/src/hpdf_page_label.c
        ../third_party/include/hpdfs/src/hpdf_page_operator.c
        ../third_party/include/hpdfs/src/hpdf_pages.c
        ../third_party/include/hpdfs/src/hpdf_real.c
        ../third_party/include/hpdfs/src/hpdf_streams.c
        ../third_party/include/hpdfs/src/hpdf_string.c
        ../third_party/include/hpdfs/src/hpdf_u3d.c
        ../third_party/include/hpdfs/src/hpdf_utils.c
        ../third_party/include/hpdfs/src/hpdf_xref.c
        ../third_party/include/hpdfs/src/hpdf_pdfa.c
        ../third_party/include/hpdfs/src/hpdf_3dmeasure.c
        ../third_party/include/hpdfs/src/hpdf_exdata.c
        ../third_party/include/hpdfs/src/hpdf_encoder_utf.c
        

        ) #demo sonrası WIN32 konsolu kapar


target_link_libraries(demo ${LIBRARIES})
