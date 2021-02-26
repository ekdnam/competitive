package dmh.iiser;

import java.util.Arrays;
import java.util.Scanner;

public class BankersAlgo {
  protected Scanner sc = new Scanner(System.in);
  /**
   * Number of processes
   */
  protected Integer n;
  /**
   * Number of resources
   */
  protected Integer m;
  /**
   * Resources currently allocated to each process
   *
   * <p><b>Size</b> n*m</p>
   */
  protected Integer[][] allocationMatrix;
  /**
   * It stores the maximum number of each resources that can be
   * acquired by each process
   *
   * <p><b>Size</b> n*m</p>
   */
  protected Integer[][] maxMatrix;
  /**
   * Total number of instances available for each resource
   *
   * <p><b>Size</b> 1*m</p>
   */
  protected Integer[] availabilityMatrix;
  /**
   * It stores the number of remaining resources required by each process to
   * complete it's task
   *
   * <p><b>Size</b> n*m</p>
   *
   * <p><b>Formula:</b></p>
   * <p><i>need[i][j] = max[i][j] - allocation[i][j]</i></p>
   */
  protected Integer[][] needMatrix;
  /**
   * Maintains the available resources
   *
   * <p><b>Size</b> m</p>
   */
  protected Integer[] workArray;
  /**
   * Stores the finish status of all processes
   *
   * <p><b>Size</b> n</p>
   */
  protected Integer[] finishArray;

  /**
   * Stores the safe sequence
   *
   * <p><b>Size</b> n</p>
   */
  protected Integer[] safeSequence;

  public BankersAlgo(Integer n, Integer m) {
    this.n = n;
    this.m = m;
    allocationMatrix = new Integer[n][m];
    maxMatrix = new Integer[n][m];
    availabilityMatrix = new Integer[m];
    needMatrix = new Integer[n][m];
    workArray = new Integer[m];
    finishArray = new Integer[n];
    safeSequence = new Integer[n + 1];
    takeInputs();
  }

  public BankersAlgo() {
    System.out.println("Number of processes: ");
    this.n = sc.nextInt();
    System.out.println("Number of resources: ");
    this.m = sc.nextInt();
    allocationMatrix = new Integer[n][m];
    maxMatrix = new Integer[n][m];
    availabilityMatrix = new Integer[m];
    needMatrix = new Integer[n][m];
    workArray = new Integer[m];
    finishArray = new Integer[n];
    safeSequence = new Integer[n + 1];
    takeInputs();
  }

  public BankersAlgo(
    Integer n,
    Integer m,
    Integer[][] allocationMatrix,
    Integer[][] maxMatrix,
    Integer[] availabilityMatrix
  ) {
    this.n = n;
    this.m = m;
    //        int nColAM = allocationMatrix.length;
    //        int nRowAM = allocationMatrix[0].length;
    //        int nColMM = maxMatrix.length;
    //        int nRowMM = maxMatrix[0].length;
    //        int nColAvM = availabilityMatrix.length;
    //        int nRowAvM = availabilityMatrix[0].length;
    this.allocationMatrix = new Integer[n][m];
    this.maxMatrix = new Integer[n][m];
    this.availabilityMatrix = new Integer[m];
    needMatrix = new Integer[n][m];
    workArray = new Integer[m];
    finishArray = new Integer[n];
    safeSequence = new Integer[n + 1];
    int[] nColArray = {
      allocationMatrix.length,
      maxMatrix.length,
      availabilityMatrix.length,
    };
    int[] nRowArray = { allocationMatrix[0].length, maxMatrix[0].length, n };
    boolean[] checks = { true, true };
    for (int i = 0; i < 3; i++) {
      if (nColArray[i] != m) {
        checks[0] = false;
      }
      if (nRowArray[i] != n) {
        checks[1] = false;
      }
    }
    if (!checks[0]) {
      System.out.println("Column dimensions are not correct");
    }
    if (!checks[1]) {
      System.out.println("Row dimensions are not correct");
    }
    if (checks[0] && checks[1]) {
      this.allocationMatrix = allocationMatrix;
      this.availabilityMatrix = availabilityMatrix;
      this.maxMatrix = maxMatrix;
    }
  }

  public void setAllocationMatrix() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        allocationMatrix[i][j] = sc.nextInt();
      }
    }
  }

  public void setMaxMatrix() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        maxMatrix[i][j] = sc.nextInt();
      }
    }
  }

  public void setAvailabilityMatrix() {
    for (int i = 0; i < m; i++) {
      availabilityMatrix[i] = sc.nextInt();
    }
  }

  public void initializeNeedMatrix() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        needMatrix[i][j] = maxMatrix[i][j] - allocationMatrix[i][j];
      }
    }
  }

  public void initializeFinishArray() {
    for (int i = 0; i < n; i++) {
      finishArray[i] = 0;
    }
  }

  public void initializeWorkArray() {
    if (m >= 0) System.arraycopy(availabilityMatrix, 0, workArray, 0, m);
  }

  public void showWorkArray() {
    for (int i = 0; i < m; i++) {
      //            System.out.printf("%-22s%-22s", workArray[i], "|");
      System.out.print(workArray[i] + "|");
    }
    System.out.println();
  }

  public void showAllocationMatrix() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        System.out.print(allocationMatrix[i][j] + " ");
        //                System.out.printf("%-22s%-22s", allocationMatrix[i][j], "|");
      }
      System.out.println();
    }
    System.out.println();
  }

  public void showAvailabilityMatrix() {
    for (int i = 0; i < m; i++) {
      System.out.print(availabilityMatrix[i] + " ");
    }
    System.out.println();
  }

  public void showMaxMatrix() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        System.out.print(maxMatrix[i][j] + " ");
        //                System.out.printf("%-22s%-22s", allocationMatrix[i][j], "|");
      }
      System.out.println();
    }
    System.out.println();
  }

  public void showNeedMatrix() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        System.out.print(needMatrix[i][j] + " ");
        //                System.out.printf("%-22s%-22s", allocationMatrix[i][j], "|");
      }
      System.out.println();
    }
    System.out.println();
  }

  public void showFinishArray() {
    for (int i = 0; i < n; i++) {
      System.out.print(finishArray[i] + " ");
    }
    System.out.println();
  }

  public void showSafeSequence() {
    for (int i = 0; i < n; i++) {
      System.out.print(safeSequence[i] + " ");
    }
    System.out.println();
  }

  public void takeInputs() {
    System.out.println("Enter values for allocation matrix: ");
    setAllocationMatrix();
    System.out.println("Enter values for max matrix: ");
    setMaxMatrix();
    System.out.println("Enter values for availabilty matrix: ");
    setAvailabilityMatrix();
    System.out.println("Initializing");
  }

  public void runAlgorithm() {
    initializeNeedMatrix();
    initializeFinishArray();
    initializeWorkArray();
    int count = 0;
    int[] work = new int[m];
    for (int i = 0; i < m; i++) {
      work[i] = availabilityMatrix[i];
    }

    while (count < n) {
      boolean flag = false;
      for (int i = 0; i < n; i++) {
        if (!visited[i]) {
          int j;
          for (j = 0; j < m; j++) {
            if (needMatrix[i][j] > work[j]) break;
          }
          if (j == m) {
            safeSequence[count++] = i;
            visited[i] = true;
            flag = true;

            for (j = 0; j < m; j++) {
              work[j] = work[j] + allocationMatrix[i][j];
            }
          }
        }
      }
      if (!flag) {
        break;
      }
    }
  }

  void runAlgo2() {
    initializeNeedMatrix();
    initializeFinishArray();
    initializeWorkArray();
    int safeSequenceIterator = 0;
    boolean[] visited = new boolean[n];
    Arrays.fill(visited, false);
    while (safeSequenceIterator < n) {
      boolean flag = false;
      for (int i = 0; i < n; i++) {
        if (!visited[i]) {
          int j;
          for (j = 0; j < m; j++) {
            if (needMatrix[i][j] > workArray[j]) {
              break;
            }
        }
            if (j == m) {
              safeSequence[safeSequenceIterator++] = i;
              visited[i] = true;
              flag = true;

              for (j = 0; j < m; j++) {
                workArray[j] = workArray[j] + allocationMatrix[i][j];
              }
            }
          }
        }
        if (!flag) {
          break;
        }
      }
    }


  

  public static void main(String[] argv) {
    BankersAlgo bankersAlgo = new BankersAlgo();
    bankersAlgo.runAlgorithm();
    bankersAlgo.showSafeSequence();
  }
}
