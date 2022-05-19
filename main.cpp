#include "hpdf.h"
#include <cstdio>
#include <string>
#include <sstream>      // std::stringstream
#include <vector>


int main (int argc, char **argv)
{
    const char *page_title = "şiçğü deneme";

    HPDF_Doc  pdf;
    HPDF_Font font;
    HPDF_Page page;
    const char* fname="demo.pdf";

    float tw;

    pdf = HPDF_New (nullptr, NULL);
    if (!pdf) {
        printf ("error: cannot create PdfDoc object\n");
        return 1;
    }  
    
    /* set compression mode */
    HPDF_SetCompressionMode (pdf, HPDF_COMP_ALL);

    /* create default-font */
    font = HPDF_GetFont (pdf, "Helvetica", "ISO8859-9");

    /* add a new page object. */
    page = HPDF_AddPage (pdf);


    /* print the title of the page (with positioning center). */
    const int fontSize=12;
    HPDF_Page_SetFontAndSize (page, font, fontSize);
    HPDF_Page_SetTextLeading(page,fontSize*0.55);

    HPDF_Page_BeginText (page);
    std::string s =R"(
#
#  URL http://libharu.org/
#
#  Copyright 2000-2006 (c) Takeshi Kanno
#  Copyright 2007-2009 (c) Antony Dovgal et al.
#

See INSTALL for instructions on how to install libHaru.

*
* What is Haru Free PDF Library?
*
Haru is a free, cross platform, open-sourced software library for generating 
PDF. It supports the following features.

   1. Generating PDF files with lines, text, images.
   2. Outline, text annotation, link annotation.
   3. Compressing document with deflate-decode.
   4. Embedding PNG, Jpeg images.
   5. Embedding Type1 font and TrueType font.
   6. Creating encrypted PDF files.
   7. Using various character set (ISO8859-1~16, MSCP1250~8, KOI8-R).
   8. Supporting CJK fonts and encodings.

You can add the feature of PDF creation by using Haru without understanding 
complicated internal structure of PDF.

*
* The differences from the previous version 
*

The biggest differences are that all code is written in C. 
To our regret, because internal structures changed greatly, The API is not 
compatible with previous version.

However, the new-version has the following advantages compared with the 
previous version.

 1. Supported shared-library build.
    A new-version library is able to be built as shared-library.
 2. The performance has been greatly improved.
    A new-version library is about 4-15 times faster than a previous version. 
 3. Supported more features.
    TrueType font, 128 bit encryption, arc function, and so on.

*
* Supporting platforms
*
Haru is written in ANSI-C and should compile easily with any compliant C 
compiler.
I inspected Haru in the following environment and make files for these 
environments are included in a package.

   1. Cygwin + GCC (Microsoft Windows)
   2. Cygwin + MinGW (Microsoft Windows)
   3. MSYS + MinGW (Microsoft Windows)
   3. Microsoft VC++ (Microsoft Windows)
   4. Borland C++ (Microsoft Windows)
   5. GCC (Linux, FreeBSD, NetBSD, Solaris...)

Also on platforms except the above, it is easy to build HARU. If you success to build HARU on other platforms, please send makefile to me.
In addition, ZLIB and PNGLIB are required when you want to use the features of 
compression and embedding PNG images. (In the case of Windows, static library 
files for several compilers are included in the package for WIndows.  In the 
case of  most of UNIX, these libraries are usually installed.)
)";
    std::stringstream modifiedStr;

    std::stringstream ss(s);
    std::string line;
    while (std::getline(ss, line, '\n')) {
        
        for (unsigned i = 0; i < line.length(); i += 85) {
            modifiedStr << line.substr(i, 85) << "\n";
        }   
        modifiedStr << "\n";    
    }
        

    HPDF_Page_TextRect(page, fontSize, fontSize*70, HPDF_Page_TextWidth (page, modifiedStr.str().c_str()), 0, modifiedStr.str().c_str(),
		       HPDF_TALIGN_LEFT, nullptr);
    HPDF_Page_EndText (page);

    /* save the document to a file */
    HPDF_SaveToFile (pdf, fname);

    /* clean up */
    HPDF_Free (pdf);

    return 0;
}