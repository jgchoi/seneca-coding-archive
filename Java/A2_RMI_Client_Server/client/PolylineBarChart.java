
import java.awt.Color;
import java.awt.Font;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.axis.CategoryAxis;
import org.jfree.chart.axis.CategoryLabelPositions;
import org.jfree.chart.axis.NumberAxis;
import org.jfree.chart.labels.CategoryItemLabelGenerator;
import org.jfree.chart.labels.ItemLabelAnchor;
import org.jfree.chart.labels.ItemLabelPosition;
import org.jfree.chart.labels.StandardCategoryItemLabelGenerator;
import org.jfree.chart.plot.CategoryPlot;
import org.jfree.chart.plot.DatasetRenderingOrder;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.renderer.category.BarRenderer;
import org.jfree.data.category.DefaultCategoryDataset;
import org.jfree.ui.TextAnchor;

public class PolylineBarChart {

	public JFreeChart getChart(String[][] s, int year) {

		//data container
		DefaultCategoryDataset dataset = new DefaultCategoryDataset();

		// data       
		for(int i = 0 ; i < s.length ; i ++)
		{
			dataset.addValue(Integer.parseInt(s[i][0]), s[i][1], s[i][2]);
		}

		final BarRenderer renderer = new BarRenderer();


		final CategoryItemLabelGenerator generator = new StandardCategoryItemLabelGenerator();
		final ItemLabelPosition p_center = new ItemLabelPosition(
				ItemLabelAnchor.CENTER, TextAnchor.CENTER
				);

		Font f = new Font("Gulim", Font.BOLD, 5);
		Font axisF = new Font("Gulim", Font.PLAIN, 5);

		renderer.setBaseItemLabelGenerator(generator);
		renderer.setBaseItemLabelsVisible(true);
		renderer.setBasePositiveItemLabelPosition(p_center);
		renderer.setBaseItemLabelFont(f);

		renderer.setSeriesPaint(0, new Color(0,162,255));

		// Graph2     
		renderer.setSeriesPaint(0, new Color(232,168,255));
		renderer.setBaseItemLabelFont(f);
		renderer.setBasePositiveItemLabelPosition(p_center);
		renderer.setBaseItemLabelGenerator(generator);
		renderer.setBaseItemLabelsVisible(true);

		// plot 
		final CategoryPlot plot = new CategoryPlot();

		// plot 
		plot.setDataset(1,dataset);
		plot.setRenderer(1,renderer);


		// plot 
		plot.setOrientation(PlotOrientation.VERTICAL);            
		plot.setRangeGridlinesVisible(true);                       
		plot.setDomainGridlinesVisible(true);                     

		plot.setDatasetRenderingOrder(DatasetRenderingOrder.FORWARD);

		plot.setDomainAxis(new CategoryAxis());           
		plot.getDomainAxis().setTickLabelFont(axisF); 
		plot.getDomainAxis().setCategoryLabelPositions(CategoryLabelPositions.STANDARD);    

		plot.setRangeAxis(new NumberAxis());                
		plot.getRangeAxis().setTickLabelFont(axisF);  

		final JFreeChart chart = new JFreeChart(plot);
		chart.setTitle(s[0][1] + " in " + year);

		return chart;
	}

}
