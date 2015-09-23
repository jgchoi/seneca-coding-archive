package ca.jgchoi.androidguide;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_about) {
            //Dialog box - Copied from: http://ccdev.tistory.com/12
            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setTitle("About Developer")
                    .setMessage("Full Name: Jung Geon Choi\n" +
                            "Program: BSD")
                    .setCancelable(true)
                    .setPositiveButton("Close", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int whichButton) {
                            dialog.cancel();
                        }
                    });

            AlertDialog dialog = builder.create();
            dialog.show();

            return true;
        }

        if (id == R.id.action_help) {
            //copied from: http://developer.android.com/training/basics/firstapp/starting-activity.html
            Intent intent = new Intent(this,Help.class);
            startActivity(intent);
            return true;
        }


        return super.onOptionsItemSelected(item);
    }

    public void openTerminology(View view)
    {
        Intent intent = new Intent(this,terminology.class);
        startActivity(intent);
    }
}
