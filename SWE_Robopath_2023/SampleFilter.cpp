#include "pch.h"
#include "SampleFilter.h"

Logic::SampleFilter::SampleFilter(UserInterface::RoboPathForm^ UI) {
    UIControl = UI;
}
System::Boolean Logic::SampleFilter::FilterData(Projectdata::RoboPath^ RoboPathData) {
    try
    {
        int iCount = 0;
        System::Double iSampleCount = RoboPathData->GetSampleSize();
        bool bCheckOncePerCycle = true;
        Projectdata::RoboPathStruct<System::Double>^ rpsSumSamples = gcnew Projectdata::RoboPathStruct<System::Double>();
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstRawData = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>(RoboPathData->GetlstRawPathData());
        System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>^ lstFilteredData = gcnew System::Collections::Generic::List<Projectdata::RoboPathStruct<System::Double>^>();

        lstFilteredData->Add(lstRawData[0]);

        for (int i = 1; i < lstRawData->Count-1; i++) {

            if (i + iSampleCount > lstRawData->Count - 2 && bCheckOncePerCycle) {
                iSampleCount = (lstRawData->Count - i) - 1;
            }

            bCheckOncePerCycle = false;

            rpsSumSamples->dTimestamp += lstRawData[i]->dTimestamp;
            rpsSumSamples->dX += lstRawData[i]->dX;
            rpsSumSamples->dY += lstRawData[i]->dY;
            rpsSumSamples->dZ += lstRawData[i]->dZ;
            rpsSumSamples->dXx += lstRawData[i]->dXx;
            rpsSumSamples->dXy += lstRawData[i]->dXy;
            rpsSumSamples->dXz += lstRawData[i]->dXz;
            rpsSumSamples->dYx += lstRawData[i]->dYx;
            rpsSumSamples->dYy += lstRawData[i]->dYy;
            rpsSumSamples->dYz += lstRawData[i]->dYz;
            rpsSumSamples->dZx += lstRawData[i]->dZx;
            rpsSumSamples->dZy += lstRawData[i]->dZy;
            rpsSumSamples->dZz += lstRawData[i]->dZz;
            iCount++;

            if (iCount == iSampleCount) {
                rpsSumSamples->dTimestamp /= iSampleCount;
                rpsSumSamples->dX /= iSampleCount;
                rpsSumSamples->dY /= iSampleCount;
                rpsSumSamples->dZ /= iSampleCount;
                rpsSumSamples->dXx /= iSampleCount;
                rpsSumSamples->dXy /= iSampleCount;
                rpsSumSamples->dXz /= iSampleCount;
                rpsSumSamples->dYx /= iSampleCount;
                rpsSumSamples->dYy /= iSampleCount;
                rpsSumSamples->dYz /= iSampleCount;
                rpsSumSamples->dZx /= iSampleCount;
                rpsSumSamples->dZy /= iSampleCount;
                rpsSumSamples->dZz /= iSampleCount;
                lstFilteredData->Add(rpsSumSamples);
                iCount = 0;
                rpsSumSamples = gcnew Projectdata::RoboPathStruct<System::Double>();
                bCheckOncePerCycle = true;
            }
        }
        lstFilteredData->Add(lstRawData[lstRawData->Count - 1]);
        RoboPathData->SetlstFilteredPathData(lstFilteredData);
        UIControl->AppendLog("Daten wurden gemittelt.\n" + lstFilteredData->Count.ToString() + " Datensätze verbleibend\n\n");
        System::Threading::Thread::Sleep(500);
        return true;
    }
    catch (System::Exception^ e)
    {
        UIControl->AppendLog("Fehler beim Filtern der Daten:\n" + e->Message + "\n\n");
        return false;
    }
}