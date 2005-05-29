/*
 * Copyright (c) 2005 Vaclav Slavik
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#include <wx/filename.h>

#include "KWQFile.h"

bool QFile::open(int mode)
{
    wxCHECK_MSG( mode == IO_ReadOnly || mode == IO_WriteOnly, false,
                 _T("invalid file access mode") );

    file.Close();

    if (mode == IO_ReadOnly)
        return file.Open(wxString(name), wxFile::read);
    else // IO_WriteOnly
        return file.Open(wxString(name), wxFile::write);
}

/*static*/
bool QFile::exists(const QString& fn)
{
    return wxFileName::FileExists(fn);
}

int QFile::readBlock(char *buffer, uint len)
{
    return file.Read(buffer, len);
}

static uint GetFileSizeImpl(wxFile& file, const wxString& name)
{
    if (file.IsOpened())
    {
        wxFileOffset pos = file.Tell();
        file.SeekEnd();
        wxFileOffset size = file.Tell();
        file.Seek(pos);
        return size;
    }
    else
    {
        wxFile file2(name, wxFile::read);
        if (!file2.IsOpened())
            return 0;
        file2.SeekEnd();
        return file2.Tell();
    }
}

uint QFile::size() const
{
    return GetFileSizeImpl(const_cast<QFile*>(this)->file, name);
}
