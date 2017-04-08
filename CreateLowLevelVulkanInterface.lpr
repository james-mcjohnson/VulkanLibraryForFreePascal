{
  Vulkan Library for FreePascal
  Copyright (c) 2017 by James McJohnson

  <Public Service Announcement>:

    "For I am not ashamed of the Good News of Christ, for it is the power of God for salvation for everyone who believes..." - Romans 1:16
    "For God so loved the world, that He gave His only begotten Son, that whosoever believeth in Him should not perish, but have everlasting life." - John 3:16

    Hear: "So faith comes by hearing, and hearing by the word of God." - Romans 10:17
    Believe: "...for unless you believe that I am He, you will die in your sins." - John 8:24
    Repent: "The times of ignorance therefore God overlooked. But now He commands that all people everywhere should repent, because He has appointed a day in which
     He will judge the world in righteousness by the Man Whom He has ordained; of which He has given assurance to all men, in that He has raised Him from the dead.” - Acts 17:30-31
    Confess: "Everyone therefore who confesses Me before men, him I will also confess before My Father Who is in heaven.
      But whoever denies Me before men, him I will also deny before My Father Who is in heaven." - Matthew 10:32-33
    Be Baptized: "Go, and make disciples of all nations, baptizing them in the name of the Father and of the Son and of the Holy Spirit" - Matthew 28:19

  </Public Service Announcement>:

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software
  without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
  persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice, the above public service announcement (in its entirety), and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
  OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
}

program CreateLowLevelVulkanInterface;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  SysUtils, Forms, MainGUI, VulkanTest
  { you can add units after this };

{$R *.res}

begin
  if FileExists('trace.trc') then
    DeleteFile('trace.trc');
  SetHeapTraceOutput('trace.trc');
  RequireDerivedFormResource:=True;
  Application.Initialize;
  Application.CreateForm(TfrmMain, frmMain);
  Application.Run;
end.

