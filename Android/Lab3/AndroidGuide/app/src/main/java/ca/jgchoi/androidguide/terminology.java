package ca.jgchoi.androidguide;

import android.content.Context;
import android.content.res.Resources;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.EditText;
import android.widget.Toast;

public class terminology extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_terminology);

        //copied from:http://developer.android.com/guide/topics/resources/string-resource.html
        Resources res = getResources();
        String [] commands = res.getStringArray(R.array.commands);

        //copied from: http://developer.android.com/reference/android/widget/AutoCompleteTextView.html
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_dropdown_item_1line,commands);
        AutoCompleteTextView textView = (AutoCompleteTextView)findViewById(R.id.autoCompleteTextView);

        //Referenced: http://www.mkyong.com/android/android-toast-example/
        textView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                String command = ((AutoCompleteTextView) findViewById(R.id.autoCompleteTextView)).getText().toString();
                Toast.makeText(getApplicationContext(),
                        getDescriptionByCommand(command), Toast.LENGTH_LONG).show();
            }
        });
        textView.setAdapter(adapter);

    }

    public void resetForm(View view)
    {
        //copied:http://www.coderanch.com/t/632457/Android/Mobile/clear-edittext-cross-button-side
        EditText et = (EditText)findViewById(R.id.autoCompleteTextView);

        et.setText("");
    }

    //copied: http://stackoverflow.com/questions/7256514/search-value-for-key-in-string-array-android
    private String getDescriptionByCommand(String command) {
        int i = -1;
        for (String cc: getResources().getStringArray(R.array.commands)) {
            i++;
            if (cc.equals(command))
                break;
        }

        return getResources().getStringArray(R.array.commandsDescription)[i];
    }


}
